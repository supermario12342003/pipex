#include "pipex.h"

void            ft_free_array_of_str(char ***ptr_to_array_of_str)
{
    size_t      i;

    if (ptr_to_array_of_str == NULL || *ptr_to_array_of_str == NULL)
        return ;
    i = 0;
    while ((*ptr_to_array_of_str)[i])
    {
        free((*ptr_to_array_of_str)[i]);
        i++;
    }
    free(*ptr_to_array_of_str);
    *ptr_to_array_of_str = NULL;
}

void            ft_clean(t_data *data)
{
    if (data)
    {
        if (data->cmd1_str)
            free(data->cmd1_str);
        if (data->cmd2_str)
            free(data->cmd2_str);
        ft_free_array_of_str(&(data->cmd1_argv));
        ft_free_array_of_str(&(data->cmd2_argv));
        ft_free_array_of_str(&(data->paths));
        if (data->cmd1_path)
            free(data->cmd1_path);
        if (data->cmd2_path)
            free(data->cmd2_path);
        free(data);
    }
}

void            ft_print_error(t_data *data, char *message, char *target)
{
    char        *err_message;

    if (data->shell)
    {
        ft_putstr_fd(data->shell, 2);
        ft_putstr_fd(": ", 2);
    }
    if (message)
        ft_putstr_fd(message, 2);
    else
    {
        err_message = strerror(errno);
        if (err_message)
            ft_putstr_fd(err_message, 2);
    }
    if (target)
    {
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(target, 2);
    }
    ft_putstr_fd("\n", 2);
}

void            ft_exit(t_data *data, int ret, char *message, char *target)
{
    if (ret)
    {
        ft_print_error(data, message, target);
    }
    ft_clean(data);
    exit(ret);
}