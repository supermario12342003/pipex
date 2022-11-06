/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:09:24 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:09:48 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (haystack[i] != '\0' && needle[j] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (needle[j] == '\0')
		return ((char *)(haystack + i - j));
	return (0);
}
