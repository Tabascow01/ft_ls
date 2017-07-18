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
	printf("start\n");
	if (argc > 1)
	{
		if (!ft_vrf_option(list, argv))
			error_illegal_option(list);
		if (!ls_core(begin))
			return (0);						// No such file or directory
		while (list)
		{
			i = 0;
			printf("list{%d}\n",j++);
			while (list->entity)
			{
				printf("id{%d} - ",list->entity->id);
				printf("type{%d} - ",list->entity->type);
				printf("option: {%s} - ", list->entity->option);
				printf("path: {%s} - ", list->entity->path);
				printf("name{%s} - ",list->entity->name);
				if (list->entity->file_stat != NULL)
					printf("fstat_Ok - ");
				printf("nblist: {%d}\n", i++);
				list->entity = list->entity->next;
			}
			list = list->next;
		}
	}
	else
	{
		if (!ls_core(list))
			return (0);						// No such file or directory
		while (list)
		{
			i = 0;
			printf("list{%d}\n",j++);
			while (list->entity)
			{
				printf("id{%d} - ",list->entity->id);
				printf("type{%d} - ",list->entity->type);
				printf("option: {%s} - ", list->entity->option);
				printf("path: {%s} - ", list->entity->path);
				printf("name{%s} - ",list->entity->name);
				if (list->entity->file_stat != NULL)
					printf("fstat_Ok - ");
				printf("nblist: {%d}\n", i++);
				list->entity = list->entity->next;
			}
			list = list->next;
		}
	}
	return (0);
}
