/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:08:26 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:08:31 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applique la fonction ’f’ à chaque caractère de la chaine de caractères
// passée en argument pour créer une nouvelle chaine de caractères (avec
// malloc(3)) résultant des applications successives de ’f’.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*resu;
	unsigned int	i;

	if (!s)
		return (NULL);
	resu = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!resu)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		resu[i] = (*f)(i, s[i]);
		i++;
	}
	resu[i] = '\0';
	return (resu);
}
