/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:02:03 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:02:05 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Écrit l’integer ’n’ sur le file descriptor donné.
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		i = (unsigned int)(-n);
	}
	else
		i = (unsigned int)n;
	if (i / 10 != 0)
		ft_putnbr_fd((int)(i / 10), fd);
	c = i % 10 + '0';
	write(fd, &c, 1);
}
