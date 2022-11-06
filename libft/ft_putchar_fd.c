/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:00:47 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:01:10 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Écrit le caractère ’c’ sur le file descriptor donné.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
