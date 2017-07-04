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

static int	ft_stock_file(t_ls *list, char *path)
{
	static int		nbfile;
	static int		old_id;

	if (list->t_dir->dir_id != old_id)
		nbfile = 0;
	old_id = list->t_dir->dir_id;
	if (!list->t_dir->t_file)
		list->t_dir->t_file = ft_init_file();
	list->t_dir->t_file->path = ft_strnew(ft_strlen(path));
	list->t_dir->t_file->path = ft_memcpy(list->t_dir->t_file->path, path, ft_strlen(path));
	list->t_dir->t_file->file_id = nbfile;
	list->t_dir->t_file->name = ft_strnew(list->dir_ent->d_namlen);
	list->t_dir->t_file->name = ft_memcpy(list->t_dir->t_file->name, list->dir_ent->d_name, list->dir_ent->d_namlen);
	printf("f_id[%d]\n", list->t_dir->t_file->file_id);
	printf("f_path[%s]\n", list->t_dir->t_file->path);
	printf("f_name[%s]\n", list->t_dir->t_file->name);
	list->t_dir->t_file = list->t_dir->t_file->next; // !
	nbfile++;
	return (0);
}

static int	ft_stock_dir(t_ls *list, char *path)
{
	static int		nbdir;
	static int		old_id;

	if (list->id != old_id)
		nbdir = 0;
	old_id = list->id;
	if (!list->t_dir)
		list->t_dir = ft_init_dir();
	list->t_dir->path = ft_strnew(ft_strlen(path));
	list->t_dir->path = ft_memcpy(list->t_dir->path, path, ft_strlen(path));
	list->t_dir->dir_id = nbdir;
	list->t_dir->name = ft_strnew(list->dir_ent->d_namlen);
	list->t_dir->name = ft_memcpy(list->t_dir->name, list->dir_ent->d_name, list->dir_ent->d_namlen);
	printf("d_id[%d]\n", list->t_dir->dir_id);
	printf("d_path[%s]\n", list->t_dir->path);
	printf("d_name[%s]\n", list->t_dir->name);
	list->t_dir = list->t_dir->next; // !
	nbdir++;
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
		if (ft_strcmp(dir_ent->d_name,".") != 0 && ft_strcmp(dir_ent->d_name, "..") != 0
				&& dir_ent->d_type == DT_DIR && dir_ent->d_name[0] != '.') // tout les directory
		{
			list->dir_ent = dir_ent;
			finalpath = ft_strnew(ft_strlen(path));
			finalpath = ft_strcpy(finalpath, path);
			finalpath = ft_strjoin(finalpath, "/");
			finalpath = ft_strjoin(finalpath, dir_ent->d_name);
			ft_stock_dir(list, finalpath);
			ft_rec(list, finalpath);
		}
		else if (ft_strcmp(dir_ent->d_name, ".") && ft_strcmp(dir_ent->d_name, ".."))// tout les files
		{
			list->dir_ent = dir_ent;
			finalpath = path;
			ft_stock_file(list, finalpath);
		}
	}
	closedir(directory);
	return (0);
}
