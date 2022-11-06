/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:43:13 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:43:15 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Supprime et libère la mémoire de l’élément passé en paramètre, et de tous
// les élements qui suivent, à l’aide de del et de free(3)
// Enfin, le pointeur initial doit être mis à NULL.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*travel;
	t_list	*next;

	if (!lst || !del)
		return ;
	travel = *lst;
	while (travel != NULL)
	{
		next = travel->next;
		(*del)(travel->content);
		free(travel);
		travel = next;
	}
	*lst = NULL;
}
