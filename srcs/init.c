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

int					ft_init_ls(t_ls *list)
{
	if (!ft_get_ls(list))
		return (0);
	return (1);
}

t_ent		*ft_init_ent()
{
	t_ent	*list_entity;

	list_entity = (t_ent *)ft_memalloc(sizeof(t_ent));
	list_entity->next = NULL;
	list_entity->id = 0;
	list_entity->path = NULL;
	list_entity->type = 0;
	list_entity->name = NULL;
	list_entity->size = 0;
	list_entity->grp = NULL;
	list_entity->user = NULL;
	list_entity->date = NULL;
	list_entity->rights = NULL;
	list_entity->inode = 0;
	list_entity->error = 0;
	list_entity->default_dir = ".";
	list_entity->directory = NULL;
	list_entity->dir_ent = NULL;
	list_entity->file_stat = NULL;
	return (list_entity);
}
/*
t_file		*ft_init_file()
{
	t_file	*list_file;

	list_file = (t_file *)ft_memalloc(sizeof(t_file));
	list_file->path = NULL;
	list_file->rights = NULL;
	list_file->name = NULL;
	list_file->date = NULL;
	list_file->size = NULL;
	list_file->user = NULL;
	list_file->user = NULL;
	list_file->grp = NULL;
	list_file->next = NULL;
	return (list_file);
}

t_dir		*ft_init_dir()
{
	t_dir	*list_dir;

	list_dir = (t_dir *)ft_memalloc(sizeof(t_dir));
	list_dir->path = NULL;
	list_dir->name = NULL;
	list_dir->rights = NULL;
	list_dir->date = NULL;
	list_dir->user = NULL;
	list_dir->grp = NULL;
	list_dir->t_file = NULL;
//	list_dir->t_file = ft_init_file();
	list_dir->next = NULL;
	return (list_dir);
}
*/

t_ls				*ft_init_list(int argc)
{
	t_ls		*list;
	static int	id;

	list = (t_ls *)ft_memalloc(sizeof(t_ls));
	list->id = id;
	list->argc = argc;
	list->option = 0;
	list->path = NULL;
	list->default_dir = ".";
	list->next = NULL;
	list->entity = ft_init_ent();
	list->directory = NULL;
	list->dir_ent = NULL;
	list->file_stat = NULL;
	list->passwd = NULL;
	return (list);
}

