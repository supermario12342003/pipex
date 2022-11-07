#include "pipex.h"

char            *ft_strjoin_triple(t_data *data, char* s1, char *s2, char *s3)
{
    char        *part1;
    char        *ret;

    part1 = ft_strjoin(s1, s2);
    if (part1 == NULL)
        ft_exit(data, 1, NULL);
    ret = ft_strjoin(part1, s3);
    free(part1);
    if (ret == NULL)
        ft_exit(data, 1, NULL);
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
        ft_exit(data, 1, NULL);
    return (ret);
}

char            **ft_get_paths(t_data *data, char **envp)
{
    size_t      i;
    char        **ret;

    if (envp == NULL)
        return (NULL);
    i = 0;
    while (envp[i])
    {
        if (ft_strncmp("PATH=", envp[i], 5) == 0)
        {
            ret = ft_split(&(envp[i][5]), ':');
            if (ret == NULL)
                ft_exit(data, 1, NULL);
            return (ret);
        }
        i++;
    }
    return (NULL);
}