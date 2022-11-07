/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoong <mchoong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:24:32 by mchoong           #+#    #+#             */
/*   Updated: 2021/01/15 22:21:15 by mchoong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define WRITE_END 1
#define READ_END 0

typedef struct s_data
{
    char        *infile;
    char        *outfile;
    int         infile_fd;
    int         outfile_fd;
    char        *cmd1_str;
    char        *cmd2_str;
    char        **cmd1_argv;
    char        **cmd2_argv;
    char        **paths;
    char        *cmd1_path;
    char        *cmd2_path;
    char        **envp;
    pid_t       pd;
    int         stat_loc;
    int         fd[2];
}				t_data;

t_data          *ft_init_data(char **argv, char **envp);
void            ft_exit(t_data *data, int ret, char *message);
void            ft_clean(t_data *data);
char            **ft_get_paths(t_data *data, char **envp);
char            *ft_get_cmd_path(t_data *data, char *prog, char **paths);
#endif