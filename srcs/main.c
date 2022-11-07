#include "pipex.h"

void    ft_parent(t_data *data)
{
    dup2(data->fd[READ_END], STDIN_FILENO);
    dup2(data->outfile_fd, STDOUT_FILENO);
    close(data->fd[READ_END]);
    close(data->fd[WRITE_END]);
    close(data->outfile_fd);
    if (waitpid(data->pd, &(data->stat_loc), WUNTRACED) == -1)
        ft_exit(data, 1, NULL);
    execve(data->cmd2_path, data->cmd2_argv, data->envp);
}

void    ft_child(t_data *data)
{
    dup2(data->fd[WRITE_END], STDOUT_FILENO);
    dup2(data->infile_fd, STDIN_FILENO);
    close(data->fd[READ_END]);
    close(data->fd[WRITE_END]);
    close(data->infile_fd);
    execve(data->cmd1_path, data->cmd1_argv, data->envp);
}

int     main(int argc, char **argv, char **envp)
{
    t_data      *data;

    data = NULL;
    if (argc != 5)
        ft_exit(data, 1, "Invalid number of arguments\n");
    data = ft_init_data(argv, envp);
    pipe(data->fd);
    data->pd = fork();
    if (data->pd == -1)
        ft_exit(data, 1, NULL);
    else if (data->pd > 0)
        ft_parent(data);
    else
        ft_child(data);
    ft_clean(data);
    return (0);
}