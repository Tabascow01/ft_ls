#include "ft_ls.h"

int		ft_get_dir(t_ls *lst)
{
	DIR				*directory;
	struct dirent	*dir_ent;
	int				i;
	t_ent			*list;

	list = lst->entity;
	i = 0;
// IF NO DIR -> DEFAULT_DIR
	if (list->path == NULL)
	{
		list->path = ft_strnew(1);
		list->path = ft_memcpy(list->path, list->default_dir
										, ft_strlen(list->default_dir));
	}
// HAS DIR
	directory = NULL;
	if ((directory = opendir(list->path)) > 0)
	{
		list->directory = directory;
		while ((dir_ent = readdir(list->directory)) > 0)
		{
			list->dir_ent = dir_ent;
			if (!ft_stock_name(list, dir_ent))
				return (0);
		}
		if (list->dir_ent != NULL)
		{
			closedir(directory);
			return (1);
		}
		else
		{
			error_noexist(lst);
			return (0);
		}
	}
	else
		error_noexist(lst);
	return (0);
}

int		ft_get_ls(t_ls *list)
{
	if (!list->next)
	{
		if(ft_get_dir(list))
			if (!ft_get_file(list))
				return (0);
			return (1);
	}
	while (list)
	{
		if (!ft_get_dir(list))
			return (0);
		list = list->next;
	}
	return (1);
}

int		ft_get_file(t_ls *lst)
{
	int				i;
	struct stat		f_stat;
	t_ent			*list;

	list = lst->entity;
	i = 0;
	if (list->dir_ent->d_type == 4)
	{
		stat(list->path, &f_stat);
		list->file_stat = &f_stat;
		return (1);
	}
	return (1);
}
