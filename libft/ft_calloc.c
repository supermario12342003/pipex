/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:44:20 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 11:44:24 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*resu;
	size_t	i;

	resu = malloc(count * size);
	if (!resu)
		return (0);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)resu)[i] = 0;
		i++;
	}
	return (resu);
}
