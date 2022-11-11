#include "pipex.h"

char            *ft_process_cmd(t_data *data, char *cmd)
{
    char            *ret;
    size_t          len;    

    if (cmd == NULL)
        ft_exit(data, 1, "Command is NULL\n", NULL);
    len = ft_strlen(cmd);
    if (len >= 2 && cmd[0] == '"' && cmd[ft_strlen(cmd) - 1] == '"')
    {
        if (len == 2)
            ft_exit(data, 1, "Command cannot be empty.\n", NULL);
        ret = ft_substr(cmd, 1, len - 2);
    }
    else
        ret = ft_strdup(cmd);
    if (ret == NULL)
        ft_exit(data, 1, NULL, NULL);
    return (ret);
}

char            **ft_get_argv(t_data *data, char *cmd)
{
    char        **ret;

    ret = ft_split(cmd, ' ');
    if (ret == NULL)
        ft_exit(data, 1, NULL, NULL);
    return (ret);
}

t_data          *ft_init_data(char **argv, char **envp)
{
    t_data      *data;

    data = malloc(sizeof(t_data));
    if (data == NULL)
        ft_exit(data, 1, NULL, NULL);
    ft_bzero(data, sizeof(t_data));
    data->paths = ft_get_paths(data, envp);
    data->infile = argv[1];
    data->outfile = argv[4];
    data->cmd1_str = ft_process_cmd(data, argv[2]);
    data->cmd1_argv = ft_get_argv(data, data->cmd1_str);
    data->cmd1_path = ft_get_cmd_path(data, data->cmd1_argv[0], data->paths);
    data->cmd2_str = ft_process_cmd(data, argv[3]);
    data->cmd2_argv = ft_get_argv(data, data->cmd2_str);
    data->cmd2_path = ft_get_cmd_path(data, data->cmd2_argv[0], data->paths);
    data->shell = ft_get_shell_name(data, envp);
    data->envp = envp;
    return (data);
}