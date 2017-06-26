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

	i = 0;
	list = ft_init_list();
	begin = list;
	if (argc > 1)
	{
		if (!ft_vrf_option(list, argv))
			error_illegal_option(list, argc);
		ls_core(begin);
		while (list)
		{
			i++;
			printf("option: %s\n", list->option);
			printf("pathname: %s\n", list->pathname);
			printf("nblist: %d\n", i);
			if (list->dir_ent)
			{
				printf("dir_ent->name[%s]\n",list->dir_ent->d_name);
				printf("dir_ent->namlen[%d]\n",list->dir_ent->d_namlen);
				printf("dir_ent->type[%u]\n",list->dir_ent->d_type);
			}
			if (list->file_stat)
			{
				printf("file_stat->mode[%x]\n",list->file_stat->st_mode);
				printf("file_stat->size[%lld]\n",list->file_stat->st_size);
				printf("file_stat->flags[%d]\n",list->file_stat->st_flags);
			}
			list = list->next;
		}
	}
	else
	{
		ls_core(list);
		while (list)
		{
			i++;
			printf("option: %s\n", list->option);
			printf("pathname: %s\n", list->pathname);
			printf("nblist: %d\n", i);
			if (list->dir_ent)
			{
				printf("dir_ent->name[%s]\n",list->dir_ent->d_name);
				printf("dir_ent->namlen[%d]\n",list->dir_ent->d_namlen);
				printf("dir_ent->type[%u]\n",list->dir_ent->d_type);
			}
			if (list->file_stat)
			{
				printf("file_stat->mode[%x]\n",list->file_stat->st_mode);
				printf("file_stat->size[%lld]\n",list->file_stat->st_size);
				printf("file_stat->flags[%d]\n",list->file_stat->st_flags);
			}
			list = list->next;
		}
	}
	return (0);
}
