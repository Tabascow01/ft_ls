/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:47:20 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:07:10 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_core(t_ls *list)
{
	int	 i;

	i = 0;
	if (list->option && list->next == NULL) //
	{
		while (list->option[i])
		{
			if (ft_vrf_all(list->option[i]))// -a
				ft_all(list);
			if (ft_vrf_rec(list->option[i]))// -R
				ft_rec(list);
			if (ft_vrf_long(list->option[i]))// -l
				ft_long(list);
			if (ft_vrf_rev(list->option[i]))// -r
				ft_rev(list);
			if (ft_vrf_time(list->option[i]))// -t
				ft_time(list);
			i++;
		}
//		ft_strdel(&list->option);// REMOVE AFTER PRINT
	}
	return (0);
}
