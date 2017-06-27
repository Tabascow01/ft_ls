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

int		ft_proc_option(t_ls *list)
{
	int		i;
	t_ls *begin;

	begin = list;
	i = 0;
	if (!ft_init_ls(list))
		return (0);
/*
	while (begin->option[i])
	{
		if (ft_vrf_all(begin->option[i]))// -a
			ft_all(list);
		if (ft_vrf_rec(begin->option[i]))// -R
			ft_rec(list);
		if (ft_vrf_long(begin->option[i]))// -l
			ft_long(list);
		if (ft_vrf_rev(begin->option[i]))// -r
			ft_rev(list);
		if (ft_vrf_time(begin->option[i]))// -t
			ft_time(list);
		i++;
	}
*/
	return (0);
}

int		ls_core(t_ls *list)
{
	int	 i;

	i = 0;
	if (list->option)
	{
		ft_proc_option(list);
//		ft_clear_option(list);
	}
	else
		ft_init_ls(list);
	return (0);
}
