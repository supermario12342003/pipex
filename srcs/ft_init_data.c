#include "pipex.h"

char            *ft_process_infile(t_data *data, char *infile)
{
    if (infile == NULL)
        ft_exit(data, 1, "Input file is NULL");
    if (access(infile, R_OK) == -1)
        ft_exit(data, 1, "Input file is not readable.\n");
    return (infile);
}

char            *ft_process_outfile(t_data *data, char *outfile)
{
    if (outfile == NULL)
        ft_exit(data, 1, "Output file is NULL");
    if (access(outfile, W_OK) == -1)
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

void            ft_init_data(t_data *data, int argc, char **argv, char **envp)
{
    if (argc != 5)
        ft_exit(data, 1, "Invalid number of arguments\n");
    data = malloc(sizeof(t_data));
    if (data == NULL)
        ft_exit(data, 1, NULL);
    ft_bzero(data, sizeof(t_data));
    data->infile = ft_process_infile(data, argv[1]);
    data->cmd1 = ft_process_cmd(data, argv[2]);
    data->cmd2 = ft_process_cmd(data, argv[3]);
    data->outfile = ft_process_outfile(data, argv[4]);
    //todo remove this
    //printf("infile: %s cmd1: [%s] cmd2: [%s] outfile: %s\n", data->infile, data->cmd1, data->cmd2, data->outfile);
    data->envp = envp;
}