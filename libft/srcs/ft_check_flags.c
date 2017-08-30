/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:10:21 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 01:46:17 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_flags(t_flags *list)
{
	if (list->space > 0 || list->sign > 0 || list->zero == '0'
			|| list->hash == '#' || list->precision > 0
			|| list->left == 1 || list->digit != NULL)
		return (1);
	return (0);
}
