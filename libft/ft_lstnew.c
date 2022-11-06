/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:44:17 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:44:19 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Alloue (avec malloc(3)) et renvoie un nouvel élément. la variable content
// est initialisée à l’aide de la valeur du paramètre content. La variable
// ’next’ est initialisée à NULL.
t_list	*ft_lstnew(void *content)
{
	t_list	*resu;

	resu = malloc(sizeof(t_list));
	if (!resu)
		return (NULL);
	resu->content = content;
	resu->next = NULL;
	return (resu);
}
