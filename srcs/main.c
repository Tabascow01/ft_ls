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
	int		i;//
	int		j;//

	j = 0;
	i = 0;
	list = ft_init_list();
	begin = list;
	if (argc > 1)
	{
		if (!ft_vrf_option(list, argv))
			error_illegal_option(list);
		if (!ls_core(begin))
			return (0);						// No such file or directory
		while (list)
		{
			i++;
			printf("id{%d}\n",list->id);
			printf("option: %s\n", list->option);
			printf("pathname: %s\n", list->pathname);
			printf("nblist: %d\n", i);
			j = 0;
			while(list->dirname[j])
				printf("dirname[%s]\n",list->dirname[j++]);
			j = 0;
			while (list->filename[j])
				printf("filename[%s]\n",list->filename[j++]);
			list = list->next;
		}
	}
	else
	{
		if (!ls_core(list))
			return (0);						// No such file or directory
		while (list)
		{
			i++;
			printf("id{%d}\n",list->id);
			printf("option: %s\n", list->option);
			printf("pathname: %s\n", list->pathname);
			printf("nblist: %d\n", i);
			j = 0;
			while(list->dirname[j])
				printf("dirname[%s]\n",list->dirname[j++]);
			j = 0;
			while (list->filename[j])
				printf("filename[%s]\n",list->filename[j++]);
			list = list->next;
		}
	}
	return (0);
}
