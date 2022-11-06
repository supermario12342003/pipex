/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:59:45 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:00:04 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The memmove() function copies len bytes from string src to string dst.
//   The two strings may overlap; the copy is always done in a non-destructive
//     manner.
void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			i++;
			((char *)dst)[len - i] = ((char *)src)[len - i];
		}
	}
	return (dst);
}
