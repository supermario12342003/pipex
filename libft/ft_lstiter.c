/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:43:41 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:43:43 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Itère sur la list lst et applique la fonction f au contenu chaque élément.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
