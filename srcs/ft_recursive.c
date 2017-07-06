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

//  Probleme sur les fichiers contenue dans un dossier ou des dossiers
//  separents les fichiers (dans l'ordre de l'ecture)
/*
static t_dir	*ft_mv_dir(t_ls *list, char *path)
{
	t_dir	*tmp;

	tmp = NULL;
	while (list)
	{
		while (list->t_dir)
		{
			if (!ft_strcmp(list->t_dir->path, path))
			{
				tmp = list->t_dir;
				return (tmp);
			}
			list->t_dir = list->t_dir->next;
		}
		list = list->next;
	}
	return (0);
}
*/
static int		ft_dir_exist(t_ls *list, char *path)
{
	int		id;
	t_ls	*begin;
	t_dir	*d;

	begin = list;
	d = list->t_dir;
	id = begin->id;
	printf("begin->dir[%d] - [%d]\n",id,d->dir_id);
	while (begin)
	{
		while (begin->t_dir)
		{
			if (!ft_strcmp(begin->t_dir->path, path))
			{
//				printf("sim dir_id[%d]\n", begin->t_dir->dir_id);
				return (1);
			}
			begin->t_dir = begin->t_dir->next;
		}
		begin = begin->next;
	}
	return (0);
}

static int		ft_stock_file(t_ls *list, char *path)
{
	int		newid;

	newid = 0;
	if (ft_dir_exist(list, path))
		printf("dir_id[%d]\n",list->t_dir->dir_id);
//	if (ft_mv_dir(list->t_dir, path))
	if (list->t_dir->t_file == NULL)
	{
		if (!list->t_dir->t_file)
			list->t_dir->t_file = ft_init_file();
		list->t_dir->t_file->file_id = 0;
	}
	else
	{
		newid = list->t_dir->t_file->file_id;
		if (!list->t_dir->t_file->next)
			list->t_dir->t_file->next = ft_init_file();
		list->t_dir->t_file = list->t_dir->t_file->next; // !
		list->t_dir->t_file->file_id = newid + 1;
	}
	list->t_dir->t_file->path = ft_strnew(ft_strlen(path));
	list->t_dir->t_file->path = ft_memcpy(list->t_dir->t_file->path, path, ft_strlen(path));
//	list->t_dir->t_file->file_id = nbfile;
	list->t_dir->t_file->name = ft_strnew(list->dir_ent->d_namlen);
	list->t_dir->t_file->name = ft_memcpy(list->t_dir->t_file->name, list->dir_ent->d_name, list->dir_ent->d_namlen);
	printf("f_id[%d]\n", list->t_dir->t_file->file_id);
	printf("f_d-id[%d]\n", list->t_dir->dir_id);
	printf("f_path[%s]\n", list->t_dir->t_file->path);
	printf("f_name[%s]\n", list->t_dir->t_file->name);
	return (0);
}

static int	ft_stock_dir(t_ls *list, char *path)
{
	int		newid;

	newid = 0;
	if (list->t_dir == NULL)
	{
		if (!list->t_dir)
			list->t_dir = ft_init_dir();
		list->t_dir->dir_id = 0;
	}
	else
	{
		newid = list->t_dir->dir_id;
		if (!list->t_dir->next)
			list->t_dir->next = ft_init_dir();
		list->t_dir = list->t_dir->next;
		list->t_dir->dir_id = newid + 1;
	}
	if (!list->t_dir)
		list->t_dir = ft_init_dir();
	list->t_dir->path = ft_strnew(ft_strlen(path));
	list->t_dir->path = ft_memcpy(list->t_dir->path, path, ft_strlen(path));
//	list->t_dir->dir_id = nbdir;
	list->t_dir->name = ft_strnew(list->dir_ent->d_namlen);
	list->t_dir->name = ft_memcpy(list->t_dir->name, list->dir_ent->d_name, list->dir_ent->d_namlen);
	printf("d_id[%d]\n", list->t_dir->dir_id);
	printf("d_path[%s]\n", list->t_dir->path);
	printf("d_name[%s]\n", list->t_dir->name);

	return (0);
}


int		ft_rec(t_ls *list, char *path)
{
	DIR				*directory;
	struct dirent	*dir_ent;
	char			*finalpath;

	if (!(directory = opendir(path)))
		return (0);
	while ((dir_ent = readdir(directory)))
	{
		list->dir_ent = dir_ent;
		if (ft_strcmp(dir_ent->d_name,".") != 0 && ft_strcmp(dir_ent->d_name, "..") != 0
				&& dir_ent->d_type == DT_DIR && dir_ent->d_name[0] != '.') // tout les directory
		{
			finalpath = ft_strnew(ft_strlen(path));
			finalpath = ft_strcpy(finalpath, path);
			finalpath = ft_strjoin(finalpath, "/");
			finalpath = ft_strjoin(finalpath, dir_ent->d_name);
			ft_stock_dir(list, finalpath);
			ft_rec(list, finalpath);
		}
		else if (ft_strcmp(dir_ent->d_name, ".") && ft_strcmp(dir_ent->d_name, "..")
					&& list->t_dir != NULL) // tout les files
			ft_stock_file(list, path);
	}
	closedir(directory);
	return (0);
}
