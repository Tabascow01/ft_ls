/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_size_nn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 16:42:16 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:01:14 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_return_size_nnnn2(t_flags *list)
{
	if (list->zero == '0' && list->digit != NULL)
		list->size += (int)ft_strlen(list->args)
			- list->nbleft - (int)ft_strlen(list->digit) - 2;
	else if (list->conv == 'c' && ft_atoi(list->args) == 0)
		list->size += (int)ft_strlen(list->args) - (int)ft_strlen(list->digit)
			- list->nbleft - 2;
	else if (list->conv == 'p')
		list->size += (int)ft_strlen(list->args) - (int)ft_strlen(list->digit)
			- list->nbleft - 2;
}
