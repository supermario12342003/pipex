/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:04:59 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:05:22 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Alloue (avec malloc(3)) et retourne une nouvelle
// chaine, résultat de la concaténation de s1 et s2.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resu;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	resu = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!resu)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		resu[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		resu[i + j] = s2[j];
		j++;
	}
	resu[i + j] = '\0';
	return (resu);
}
