/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:42:29 by rdi-marz          #+#    #+#             */
/*   Updated: 2021/11/04 11:42:36 by rdi-marz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '	' || (str[i] >= 9 && str[i] <= 13 ))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}
