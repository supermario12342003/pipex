/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:06:54 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:07:13 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (dstsize < 0)
		return (0);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (dstsize < i + 1)
		return (j + dstsize);
	k = 0;
	while (k < (dstsize - i - 1) && k < j + 1)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + j);
}
