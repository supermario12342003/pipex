/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:10:28 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:11:07 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinlist(char c, char const *list)
{
	int	i;

	i = 0;
	while (list[i] != '\0')
	{
		if (list[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_mallocresu(int lens1, int trimdeb, int trimfin, char const *s1)
{
	char	*resu;
	int		i;

	if ((lens1 - trimdeb - trimfin) < 0)
		resu = malloc (sizeof(char));
	else
		resu = malloc ((lens1 - trimdeb - trimfin + 1) * sizeof(char));
	if (!resu)
		return (NULL);
	i = trimdeb;
	while (i < lens1 - trimfin)
	{
		resu[i - trimdeb] = s1[i];
		i++;
	}
	resu[i - trimdeb] = '\0';
	return (resu);
}	

// Alloue (avec malloc(3)) et retourne une copie de la chaine ’s1’, sans
// les caractères spécifiés dans ’set’ au début et à la fin de la chaine
// de caractères.
char	*ft_strtrim(char const *s1, char const *set)
{
	int		lens1;
	int		trimdeb;
	int		trimfin;
	char	*resu;

	trimdeb = 0;
	trimfin = 0;
	if (!set || !s1)
		return (NULL);
	while (ft_isinlist(s1[trimdeb], set) == 1 && s1[trimdeb] != '\0')
		trimdeb++;
	lens1 = ft_strlen(s1);
	while (ft_isinlist(s1[lens1 - trimfin - 1], set) == 1 && trimfin < lens1)
		trimfin++;
	resu = ft_mallocresu(lens1, trimdeb, trimfin, s1);
	return (resu);
}
