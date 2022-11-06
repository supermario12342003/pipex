#include "pipex.h"

void            ft_clean(t_data *data)
{
    if (data)
    {
        if (data->cmd1)
            free(data->cmd1);
        if (data->cmd2)
            free(data->cmd2);
        free(data);
    }
}

void            ft_exit(t_data *data, int ret, char *message)
{
    if (ret)
    {
        if (message)
        {
            ft_putstr_fd(message, 2);
        }
        else
        {
            perror(NULL);
        }
    }
    ft_clean(data);
    exit(ret);
}