/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:49:40 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:10:09 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char *argv[])
{
	t_ls	*list;
	t_ls	*begin;
	int		max_len;
	int		i;//
	int		j;//

	j = 0;
	i = 0;
	list = ft_init_list(argc);
	list->prev = NULL;
	begin = list;
	max_len = 0;
	if (argc > 1)
	{
		if (!ft_vrf_option(list, argv))
			error_illegal_option(list);
		if (!ls_core(begin))
			return (0);						// No such file or directory
		if (!(max_len = ft_max_len(list)))
			return (0);
		if (!ft_display_optcore(list, max_len))
		{
			perror(list->path);// no directory exist
			return (0);
		}
	}
	else
	{
		if (!ls_core(list))
			return (0);						// No such file or directory
		if (!(max_len = ft_max_len(list)))
			return (0);
		if (!ft_display_smpcore(list, max_len))
		{
			perror(list->path);// no directory exist
			return (0);
		}
	}
	return (0);
}
