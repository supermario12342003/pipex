/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:40:57 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:41:01 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Ajoute l’élément new à la fin de la liste.
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*resu;

	if (!new || !alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	resu = *alst;
	while (resu->next != NULL)
		resu = resu->next;
	resu->next = new;
}
