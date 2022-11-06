/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:01:25 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:01:47 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Écrit La chaine de caractères ’s’ sur le file descriptor donné,
// suivie d’un retour à la ligne.
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &(s[i]), 1);
		i++;
	}
	write(fd, "\n", 1);
}
