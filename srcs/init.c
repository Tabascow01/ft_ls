/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:50:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:14:59 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_init_ls(t_ls *list)
{
	ft_get_dir(list);
}

static t_file		*ft_init_file()
{
	t_file	*list;

	list = ft_memalloc(sizeof(list));
	list->file_id = 0;
	list->path = NULL;
	list->rights = NULL;
	list->name = NULL;
	list->date = NULL;
	list->size = NULL;
	list->user = NULL;
	list->user = NULL;
	list->grp = NULL;
	list->next = NULL;
	return (list);
}

static t_dir		*ft_init_dir()
{
	t_dir	*list;

	list = ft_memalloc(sizeof(list));
	list->dir_id = 0;
	list->path = NULL;
	list->name = NULL;
	list->rights = NULL;
	list->date = NULL;
	list->user = NULL;
	list->grp = NULL;
	list->next = NULL;
	list->t_file = ft_init_file();
	return (list);
}

t_ls				*ft_init_list()
{
	t_ls *list;

	list = ft_memalloc(sizeof(list));
	list->option = 0;
	list->pathname = NULL;
	list->dirname = NULL;
	list->filename = NULL;
	list->default_dir = ".";
	list->next = NULL;
	list->t_dir = ft_init_dir();
	return (list);
}
