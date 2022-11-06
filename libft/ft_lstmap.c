/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:44:09 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:44:10 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Itère sur la liste lst et applique la fonction f au contenu de chaque
// élément. Crée une nouvelle liste résultant des applications successives
// de f. la fonction del est la pour detruire le contenu d un element si
// necessaire
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*cur_result;

	if (!lst || !f)
		return (NULL);
	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	cur_result = result;
	while (lst)
	{
		cur_result->content = (*f)(lst->content);
		if (lst->next == NULL)
			break ;
		cur_result->next = malloc(sizeof(t_list));
		if (!cur_result->next)
		{
			ft_lstclear(&result, (*del));
			return (NULL);
		}
		cur_result = cur_result->next;
		lst = lst->next;
	}
	cur_result->next = NULL;
	return (result);
}
