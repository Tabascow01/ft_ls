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
	t_file	*lst_f;
	t_dir	*lst_d;

	i = 0;
	ft_init_ls(list);
	lst_d = ft_init_dir();
	lst_f = ft_init_file();
	lst_d->t_file = lst_f;
	list->t_dir = lst_d;
	if (list->option)
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
		ft_strdel(&list->option);
	}
	return (0);
}
