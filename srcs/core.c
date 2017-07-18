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
	t_ls	*begin;

	begin = list;
	if (!ft_strchr(begin->option, 'R'))
		if (!ft_init_ls(list))
			return (0);
	if (list->option == NULL)
		return (0);
	while (list)// WRONG ERROR LOOP - TOO MANY
	{
		if (ft_strchr(list->option, 'a'))// -a
			ft_all(list);
		if (ft_strchr(list->option, 'R'))// -R
			ft_rec(list, list->path);
		if (ft_strchr(list->option, 'l'))// -l
			ft_long(list);
		if (ft_strchr(list->option, 'r'))// -r
			ft_rev(list);
		if (ft_strchr(list->option, 't'))// -t
			ft_time(list);
		list = list->next;
	}
	return (1);
}

int		ls_core(t_ls *list)
{
	int	 i;

	i = 0;
	if (list->option)
	{
		if(!ft_proc_option(list))
			return (0);
//		ft_clear_option(list);
	}
	else
		if (!ft_init_ls(list))
			return (0);
	return (1);
}
