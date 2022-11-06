#include "pipex.h"

int     main(int argc, char **argv, char **envp)
{
    t_data      *data;

    data = NULL;
    ft_init_data(data, argc, argv, envp);
    ft_exit(data, 0, NULL);
    return (0);
}