#include "pipex.h"

char            *ft_strjoin_triple(t_data *data, char* s1, char *s2, char *s3)
{
    char        *part1;
    char        *ret;

    part1 = ft_strjoin(s1, s2);
    if (part1 == NULL)
        ft_exit(data, 1, NULL, NULL);
    ret = ft_strjoin(part1, s3);
    free(part1);
    if (ret == NULL)
        ft_exit(data, 1, NULL, NULL);
    return (ret);
}

char            *ft_get_cmd_path(t_data *data, char *prog, char **paths)
{
    size_t      i;
    char        *ret;
    
    i = 0;
    if (paths)
    {  
        while (paths[i])
        {
            ret = ft_strjoin_triple(data, paths[i], "/", prog);
            if (access(ret, X_OK) == 0)
                return (ret);
            free(ret);
            i++;
        }
    }
    ret = ft_strjoin("./", prog);
    if (ret == NULL)
        ft_exit(data, 1, NULL, NULL);
    return (ret);
}

char            *ft_get_env_var_value(char **envp, char *var_name)
{
    size_t      i;
    int         len;

    if (envp == NULL)
        return (NULL);
    i = 0;
    len = ft_strlen(var_name);
    while (envp[i])
    {
        if (ft_strncmp(var_name, envp[i], len) == 0 && envp[i][len] == '=')
            return (&(envp[i][len + 1]));
        i++;
    }
    return (NULL);
}

char            **ft_get_paths(t_data *data, char **envp)
{
    char        *var_value;
    char        **ret;

    var_value = ft_get_env_var_value(envp, "PATH");
    if (var_value == NULL)
        return (NULL);
    ret = ft_split(&(var_value[5]), ':');
    if (ret == NULL)
        ft_exit(data, 1, NULL, NULL);
    return (ret);
}

char            *ft_get_shell_name(t_data *data, char **envp)
{
    char        *shell_path;
    char        **parts;
    int         index_of_last_part;
    char        *ret;

    shell_path = ft_get_env_var_value(envp, "SHELL");
    if (shell_path == NULL)
        return (NULL);
    parts = ft_split(shell_path, '/');
    if (parts == NULL)
        ft_exit(data, 1, NULL, NULL);
    index_of_last_part = 0;
    while (parts[index_of_last_part])
        index_of_last_part++;
    index_of_last_part = index_of_last_part - 1;
    ret = ft_strdup(parts[index_of_last_part]);
    ft_free_array_of_str(&parts);
    if (ret == NULL)
        ft_exit(data, 1, NULL, NULL);
    return (ret);
}