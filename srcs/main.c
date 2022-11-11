#include "pipex.h"

int             ft_process_file(t_data *data, char *file, int flag)
{
    int         file_fd;
    
    file_fd = open(file, flag);
    if (file_fd == -1)
        ft_exit(data, 1, NULL, file);
    return (file_fd);
}

void    ft_parent(t_data *data)
{
    dup2(data->fd[READ_END], STDIN_FILENO);
    dup2(data->outfile_fd, STDOUT_FILENO);
    close(data->fd[READ_END]);
    close(data->fd[WRITE_END]);
    close(data->outfile_fd);
    if (waitpid(data->pd, &(data->stat_loc), WUNTRACED) == -1)
        ft_exit(data, 1, NULL, NULL);
    data->outfile_fd = ft_process_file(data, data->outfile, O_WRONLY | O_CREAT | O_TRUNC);
    if (execve(data->cmd2_path, data->cmd2_argv, data->envp) == -1)
    {
        unlink(data->outfile);
        ft_exit(data, 1, NULL, NULL);
    }
}

void    ft_child(t_data *data)
{
    dup2(data->fd[WRITE_END], STDOUT_FILENO);
    dup2(data->infile_fd, STDIN_FILENO);
    close(data->fd[READ_END]);
    close(data->fd[WRITE_END]);
    close(data->infile_fd);
    data->infile_fd = ft_process_file(data, data->infile, O_RDONLY);
    if (execve(data->cmd1_path, data->cmd1_argv, data->envp) == -1)
    {
        close(data->infile_fd);
        ft_exit(data, 1, NULL, NULL);
    }
}

int     main(int argc, char **argv, char **envp)
{
    t_data      *data;

    data = NULL;
    if (argc != 5)
        ft_exit(data, 1, "Invalid number of arguments\n", NULL);
    data = ft_init_data(argv, envp);
    pipe(data->fd);
    data->pd = fork();
    if (data->pd == -1)
        ft_exit(data, 1, NULL, NULL);
    else if (data->pd > 0)
        ft_parent(data);
    else
        ft_child(data);
    ft_clean(data);
    return (0);
}