/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:43:26 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:43:29 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Libère la mémoire de l’élément passé en argument en utilisant la fonction
// del puis avec free(3). La mémoire de next ne doit pas être free.
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);
}
