/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:41:48 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 12:41:49 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Ajoute l’élément ’new’ au début de la liste.
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
