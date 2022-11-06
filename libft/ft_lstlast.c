/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:43:53 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:43:54 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Renvoie le dernier élément de la liste.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*resu;

	if (lst == NULL)
		return (NULL);
	resu = lst;
	while (resu->next != NULL)
	{
		resu = resu->next;
	}
	return (resu);
}
