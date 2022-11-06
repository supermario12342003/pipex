/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:04:34 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:04:49 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applique la fonction f à chaque caractère de la chaîne de caractères
// transmise comme argument, et en passant son index comme premier argument.
// Chaque caractère est transmis par adresse à f pour être modifié si
// nécessaire.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
