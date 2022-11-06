/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:58:00 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 11:58:12 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memchr() function locates the first occurrence of c (converted to an
// unsigned char) in string s.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)s)[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return (&((void *)s)[i]);
}
