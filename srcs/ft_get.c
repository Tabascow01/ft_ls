#include "ft_ls.h"

int		ft_get_dir(t_ls *list)
{
	DIR				*directory;
	struct dirent	*dir_ent;

// IF NO DIR -> DEFAULT_DIR
	if (list->pathname == NULL)
	{
		list->pathname = ft_strnew(1);
		list->pathname = ft_memcpy(list->pathname, list->default_dir
										, ft_strlen(list->default_dir));
	}
// HAS DIR
	directory = NULL;
	if ((directory = opendir(list->pathname)))
	{
		list->directory = directory;
		while ((dir_ent = readdir(list->directory)))
		{
			printf("dir_n{%s}\n",dir_ent->d_name);
			list->dir_ent = dir_ent;
//			list = list->next;
//			ft_stock_dir_infos(list);
		}
		if (list->dir_ent != NULL)
			return (1);
	}
	return (0);
}

int		ft_get_ls(t_ls *list)
{
	t_ls *begin;

	begin = list;
	if (!list->next)
	{
		if(ft_get_dir(list))
			if (ft_get_file(list))
				return (1);
	}
	while (list)
	{
		if (!ft_get_dir(list))
			return (0);
		if (!ft_get_file(list))
				return (0);
		list = list->next;
	}
	return (1);
}

int		ft_get_file(t_ls *list)
{
	int				i;
	struct stat		f_stat;

	i = 0;
	if (list->dir_ent->d_type == 4)
	{
		stat(list->pathname, &f_stat);
		list->file_stat = &f_stat;
		return (1);
	}
	return (1);
	return (0);
}

int		ft_get_infos(t_ls *list)
{
	list->next = NULL;//
	return (0);
}
