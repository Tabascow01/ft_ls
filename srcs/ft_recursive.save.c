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

/*
static int		ft_stock_file(t_file *list, struct dirent *dir_ent)
{
	t_file			*lst;
	struct dirent	*dir;

	lst = list;
	dir = dir_ent;
	return (0);
}
*/
/*
static int		ft_stock_dir(t_dir *list, struct dirent *dir_ent)
{
	if (list != NULL && dir_ent != NULL)
	{
		list->name = ft_strnew(ft_strlen(dir_ent->d_name));
		list->name = ft_memcpy(list->name, dir_ent->d_name,
									ft_strlen(dir_ent->d_name));
		return (1);
	}
	return (0);
}
*/

static int		ft_rename_path(t_ls *list)// A REVOIR
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = ft_strlen(list->pathname);
	if (list->pathname[size - 1])
		size--;
	while (size > 0 && list->pathname[size] && list->pathname[size] != '/')
		size--;
	str = ft_strnew(size);
	str = ft_memcpy(str, list->pathname , size);
	ft_strdel(&list->pathname);
	list->pathname = ft_strnew(size);
	list->pathname = ft_memcpy(list->pathname, str, size);
	return (1);
}

static int		ft_rename_path_one(t_ls *list)
{
	int		size;

	size = ft_strlen(list->default_dir);
	ft_strdel(&list->pathname);
	list->pathname = ft_strnew(size);
	list->pathname = ft_memcpy(list->pathname, list->default_dir, size);
	return (0);
}

int		ft_get_rec_dir(t_ls *list)
{
	static int			nbdir;
	DIR					*directory;
	struct dirent		*dir_ent;
	t_ls				*begin;

	begin = list;
	if (begin != NULL && nbdir >= 0)
	{
		if (!(directory = opendir(list->pathname)))
			return (0);
		while ((dir_ent = readdir(directory)))
		{
			printf("[2] ->%s<-\n",list->pathname);
			if (ft_strcmp(dir_ent->d_name,".") != 0 
					&& ft_strcmp(dir_ent->d_name, "..") != 0
					&& dir_ent->d_type == DT_DIR 
					&& dir_ent->d_name[0] != '.')
			{
				if (nbdir == 0)
				{
					list->pathname = ft_strjoin(list->pathname, "/");
					list->pathname = ft_strjoin(list->pathname, dir_ent->d_name);
				}
				else
				{
					ft_rename_path(list);
					list->pathname = ft_strjoin(list->pathname, "/");
					list->pathname = ft_strjoin(list->pathname, dir_ent->d_name);
				}
				nbdir++;
			}
//			ft_get_rec_dir(list);
		}
		return (1);
	}
	return (0);
}

/*
static int	ft_check_path(t_ls *list, int nbdir)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (list->pathname == NULL || nbdir <= 0)
		return (0);
	while (list->pathname[j] && list->pathname[j] == '.' && list->pathname[j] == '/')
			j++;
	while (list->dirname[i])
	{

//		printf("path->[%s]\ndir->[%s]\n",&list->pathname[j],list->dirname[i]);
		if (!ft_strcmp(&list->pathname[j], list->dirname[nbdir]))
		{
			ft_strdel(&list->pathname);
			list->pathname = ft_strnew(ft_strlen(list->default_dir));
			list->pathname = ft_strcpy(list->pathname, list->default_dir);
		}
		i++;
	}
	return (1);
}
*/
int		ft_rec(t_ls *list)
{
	t_ls			*begin;
	DIR				*directory;
	struct dirent	*dir_ent;
	char			*retpath;
	static int		nbdir;

	begin = list;
	if (list->id == 0 && list->next == 0)
		retpath = NULL;
	if (!(directory = opendir(list->pathname)))
		return (0);
	while ((dir_ent = readdir(directory)))
	{
		if (ft_strcmp(dir_ent->d_name,".") != 0 && ft_strcmp(dir_ent->d_name, "..") != 0
				&& dir_ent->d_type == DT_DIR && dir_ent->d_name[0] != '.')
		{
			printf("[1] ->%s<-\n",list->pathname);
			if (nbdir == 0)
			{
				list->pathname = ft_strjoin(list->pathname, "/");
				list->pathname = ft_strjoin(list->pathname, dir_ent->d_name);
			}
			else
			{
				ft_rename_path_one(list);
				list->pathname = ft_strjoin(list->pathname, "/");
				list->pathname = ft_strjoin(list->pathname, dir_ent->d_name);
				printf("[3] ->%s<-\n", list->pathname);
			}
			if (!ft_get_rec_dir(list))
				return (0);
			nbdir += 1;
			ft_rec(list);
		}
		else
		{
//			printf("rejected for recursive{%s}\n",dir_ent->d_name);
		}
	}
	closedir(directory);
	return (0);
}
