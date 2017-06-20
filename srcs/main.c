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

	list = ft_init_list();
	if (argc < 1)
		error_usage();
	else if (argc > 0)
	{
		if (ft_vrf_option(list, argv[1]))
			error_illegal_option(list);
		else
			list->option = NULL;
		ls_core(list);
	}
	else
		error_usage_end();
	return (0);
}
