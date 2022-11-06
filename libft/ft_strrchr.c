/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:10:01 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:10:10 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr() function locates the first occurrence of c (converted to a
// char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is `\0', the func-
// tions locate the terminating `\0'.
// The strrchr() function is identical to strchr(), except it locates the
// last occurrence of c.
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != (char)c && i >= 0)
		i--;
	if (i == -1)
		return (NULL);
	return (&(((char *)s)[i]));
}
