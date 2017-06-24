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
	if (argc > 3)
		error_usage();
	else if (argc < 4)
	{
		if (argv[1] != NULL)
			if (!ft_vrf_option(list, argv))
				error_illegal_option(list);
		printf("option: %s\n", list->option);
		printf("pathname: %s\n", list->pathname);
		ls_core(list);
	}
	return (0);
}
