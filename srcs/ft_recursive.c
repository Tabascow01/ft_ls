/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:58:40 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:15:18 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_stock_file(t_ent *list, char *path)
{
	int				newid;
	struct dirent	*entity;
	t_ent			*prev_lst;

	newid = list->id;
	entity = list->dir_ent;
	if (newid > 0)
	{
		while (list->next)
		{
			list = list->next;
			newid++;
		}
		prev_lst = list;
		list->next = ft_init_ent();
		list->next->dir_ent = entity;
		list->next->option = ft_strnew(ft_strlen(list->option));
		list->next->option = ft_memcpy(list->next->option, list->option, ft_strlen(list->option));
		list = list->next;
		list->prev = prev_lst;
	}
	list->id = newid + 1;
	list->path = ft_strnew(ft_strlen(path));
	list->path = ft_memcpy(list->path, path, ft_strlen(path));
	list->name = ft_strnew(list->dir_ent->d_namlen);
	list->name = ft_memcpy(list->name, list->dir_ent->d_name, list->dir_ent->d_namlen);
	list->type = list->dir_ent->d_type;
//	printf("f_id[%d] - f_path[%s] - f_name[%s] - f_type[%d]\n", list->id, list->path, list->name, list->type);
	return (0);
}

static int	ft_stock_dir(t_ent *list, char *path)
{
	int				newid;
	struct dirent	*entity;
	t_ent			*prev_lst;

	newid = list->id;
	entity = list->dir_ent;
	if (newid > 0)
	{
		while (list->next)
		{
			list = list->next;
			newid++;
		}
		prev_lst = list;
		list->next = ft_init_ent();
		list->next->dir_ent = entity;
		list->next->option = ft_strnew(ft_strlen(list->option));
		list->next->option = ft_memcpy(list->next->option, list->option, ft_strlen(list->option));
		list = list->next;
		list->prev = prev_lst;
	}
	list->id = newid + 1;
	list->path = ft_strnew(ft_strlen(path));
	list->path = ft_memcpy(list->path, path, ft_strlen(path));
	list->name = ft_strnew(list->dir_ent->d_namlen);
	list->name = ft_memcpy(list->name, list->dir_ent->d_name, list->dir_ent->d_namlen);
	list->type = list->dir_ent->d_type;
//	printf("d_id[%d] - d_path[%s] - d_name[%s] - d_type[%d]\n", list->id, list->path, list->name, list->type);
	return (0);
}


int		ft_rec(t_ls *list, char *path)
{
	DIR				*directory;
	struct dirent	*dir_ent;
	char			*finalpath;
	t_ent			*ent;

	ent = list->entity;
	if (path == NULL)
	{
		path = ft_strnew(1);
		path = ft_memcpy(path,list->default_dir, 1);
	}
	if (!(directory = opendir(path)))
	{
		perror("Directory error");
		return (0);
	}
	while ((dir_ent = readdir(directory)) > 0)
	{
		ent->dir_ent = dir_ent;
		if (ft_strcmp(dir_ent->d_name,".") != 0 && ft_strcmp(dir_ent->d_name, "..") != 0
				&& dir_ent->d_type == DT_DIR) // tout les directory
		{
			finalpath = ft_strnew(ft_strlen(path));
			finalpath = ft_strcpy(finalpath, path);
			finalpath = ft_strjoin(finalpath, "/");
			finalpath = ft_strjoin(finalpath, dir_ent->d_name);
			ft_stock_dir(ent, finalpath);
			ft_rec(list, finalpath);
		}
		else if (ft_strcmp(dir_ent->d_name, ".") && ft_strcmp(dir_ent->d_name, "..")) // tout les files
			ft_stock_file(ent, path);
	}
	closedir(directory);
	return (0);
}
