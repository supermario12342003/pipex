/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:02:54 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:03:15 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbword(char const *s, char c)
{
	int	i;
	int	resu;

	i = 0;
	resu = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		resu++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (resu);
}

static void	ft_coresplit(char const *s, char c, int i, char **resu)
{
	int		wordlen;
	int		wnb;

	wnb = 0;
	while (s[i] != '\0')
	{
		wordlen = 0;
		while (s[i + wordlen] != c && s[i + wordlen] != '\0')
			wordlen++;
		resu[wnb] = malloc((wordlen + 1) * sizeof (char));
		wordlen = 0;
		while (s[i] != c && s[i] != '\0')
		{
			resu[wnb][wordlen] = s[i];
			i++;
			wordlen++;
		}
		resu[wnb][wordlen] = '\0';
		wnb++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	resu[wnb] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**resu;

	if (!s)
		return (NULL);
	resu = malloc((ft_nbword(s, c) + 1) * sizeof (char *));
	if (!resu)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	ft_coresplit(s, c, i, resu);
	return (resu);
}
