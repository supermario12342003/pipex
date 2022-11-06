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

typedef struct s_data
{
    char        *infile;
    char        *outfile;
    char        *cmd1;
    char        *cmd2;
    char        **envp;
}				t_data;

void            ft_init_data(t_data *data, int argc, char **argv, char **envp);
void            ft_exit(t_data *data, int ret, char *message);

#endif