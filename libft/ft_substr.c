/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:11:20 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:11:30 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Alloue (avec malloc(3)) et retourne une chaine de caractères issue
// de la chaine ’s’. Cette nouvelle chaine commence à l’index ’start’
// et a pour taille maximale ’len’
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*resu;
	unsigned int	slen;

	if (s == NULL || len < 0 || start < 0)
		return (NULL);
	slen = ft_strlen(s);
	if (slen >= start + len)
		resu = malloc((len + 1) * sizeof(char));
	else if (slen > start)
		resu = malloc((slen - start + 2) * sizeof(char));
	else
		resu = malloc(sizeof(char));
	if (!resu)
		return (NULL);
	i = 0;
	while (i < len && (i + start) < slen && s[i + start] != '\0')
	{
		resu[i] = s[i + start];
		i++;
	}
	resu[i] = '\0';
	return (resu);
}
