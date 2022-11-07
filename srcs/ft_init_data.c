#include "pipex.h"

char            *ft_process_infile(t_data *data, char *infile)
{
    if (infile == NULL)
        ft_exit(data, 1, "Input file is NULL");
    if (access(infile, R_OK) == -1)
        ft_exit(data, 1, "Input file is not readable.\n");
    data->infile_fd = open(infile, O_RDONLY);
    if (data->infile_fd == -1)
        ft_exit(data, 1, NULL);
    return (infile);
}

char            *ft_process_outfile(t_data *data, char *outfile)
{
    if (outfile == NULL)
        ft_exit(data, 1, "Output file is NULL");
    if (access(outfile, W_OK) == -1)
        ft_exit(data, 1, "Output file is not writable.\n");
    data->outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC);
    if (data->outfile_fd == -1)
        ft_exit(data, 1, "Output file is not writable.\n");
    return (outfile);
}

char            *ft_process_cmd(t_data *data, char *cmd)
{
    char            *ret;
    size_t          len;    

    if (cmd == NULL)
        ft_exit(data, 1, "Command is NULL");
    len = ft_strlen(cmd);
    if (len >= 2 && cmd[0] == '"' && cmd[ft_strlen(cmd) - 1] == '"')
    {
        if (len == 2)
            ft_exit(data, 1, "Command cannot be empty.\n");
        ret = ft_substr(cmd, 1, len - 2);
    }
    else
        ret = ft_strdup(cmd);
    if (ret == NULL)
        ft_exit(data, 1, NULL);
    return (ret);
}

char            **ft_get_argv(t_data *data, char *cmd)
{
    char        **ret;

    ret = ft_split(cmd, ' ');
    if (ret == NULL)
        ft_exit(data, 1, NULL);
    return (ret);
}

t_data          *ft_init_data(char **argv, char **envp)
{
    t_data      *data;

    data = malloc(sizeof(t_data));
    if (data == NULL)
        ft_exit(data, 1, NULL);
    ft_bzero(data, sizeof(t_data));
    data->paths = ft_get_paths(data, envp);
    data->infile = ft_process_infile(data, argv[1]);
    data->cmd1_str = ft_process_cmd(data, argv[2]);
    data->cmd1_argv = ft_get_argv(data, data->cmd1_str);
    data->cmd1_path = ft_get_cmd_path(data, data->cmd1_argv[0], data->paths);
    data->cmd2_str = ft_process_cmd(data, argv[3]);
    data->cmd2_argv = ft_get_argv(data, data->cmd2_str);
    data->cmd2_path = ft_get_cmd_path(data, data->cmd2_argv[0], data->paths);
    data->outfile = ft_process_outfile(data, argv[4]);
    data->envp = envp;
    return (data);
}