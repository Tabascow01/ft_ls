/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags_n.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 01:48:06 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 01:56:39 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_process_flags_nnnn(t_flags *list)
{
	if (((int)ft_strlen(list->digit) > 0 && (list->conv == 'S'
			|| list->conv == 'C')
			&& list->left == 0 && list->zero == 0)
			|| ((list->conv == 'S' || list->conv == 'C')
			&& list->zero == '0'
			&& list->precision == 0))
		ft_wdigitflag(list);
	else if (((int)ft_strlen(list->digit) > 0 && (list->conv == 'S'
			|| list->conv == 'C')
			&& list->left > 0 && list->zero == 0)
			|| ((list->conv == 'S' || list->conv == 'C')
			&& list->zero == '0'
			&& list->precision == 0))
		ft_wldigitflag(list);
	else if (list->zero == '0' && (list->conv == 'C' || list->conv == 'S')
			&& list->precision == 0)
		ft_wzeroflag(list);
}
