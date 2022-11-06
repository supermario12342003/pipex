/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:44:35 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:44:39 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compte le nombre d’éléments de la liste.
int	ft_lstsize(t_list *lst)
{
	t_list	*resu;
	int		i;

	if (lst == NULL)
		return (0);
	i = 1;
	resu = lst;
	while (resu->next != NULL)
	{
		i++;
		resu = resu->next;
	}
	return (i);
}
