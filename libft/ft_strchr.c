/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:03:31 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:03:55 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr() function locates the first occurrence of c (converted to a
// char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is `\0', the func-
// tions locate the terminating `\0'.
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&(((char *)s)[i]));
}
