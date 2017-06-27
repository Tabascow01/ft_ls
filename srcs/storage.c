#include "ft_ls.h"


int		ft_stock_fname(t_ls *list)
{
	int			i;
	static int	pass;

	i = 0;
	if (list->filename == NULL)
	{
		if (pass > 0)
			pass = 0;
		list->filename = (char **)ft_memalloc(sizeof(char *) * 256);
		(*list->filename) = ft_strnew(list->dir_ent->d_namlen);
		(*list->filename) = ft_memcpy((*list->filename), list->dir_ent->d_name,
										list->dir_ent->d_namlen);
	}
	else if (list->filename != NULL)
	{
		list->filename[pass] = ft_strnew(list->dir_ent->d_namlen);
		list->filename[pass] = ft_memcpy(list->filename[pass], list->dir_ent->d_name,
										list->dir_ent->d_namlen);
	}
	pass++;
//	list->filename[pass] = 0;
	return (0);
}


int		ft_stock_dname(t_ls *list)
{
	int			i;
	static int	pass;

	i = 0;
	if (list->dirname == NULL)
	{
		if (pass > 0)
			pass = 0;
		list->dirname = (char **)ft_memalloc(sizeof(char *) * 256);
		(*list->dirname) = ft_strnew(list->dir_ent->d_namlen);
		(*list->dirname) = ft_memcpy((*list->dirname), list->dir_ent->d_name,
										list->dir_ent->d_namlen);
	}
	else if (list->dirname != NULL)
	{
		list->dirname[pass] = ft_strnew(list->dir_ent->d_namlen);
		list->dirname[pass] = ft_memcpy(list->dirname[pass], list->dir_ent->d_name,
										list->dir_ent->d_namlen);
	}
	pass++;
//	list->dirname[pass] = 0;
	return (0);
}


int		ft_stock_name(t_ls *list)
{
	if (list->dir_ent != NULL)
	{
		if (list->dir_ent->d_type == 4)
			ft_stock_dname(list);
		else
			ft_stock_fname(list);
	}
	return (0);
}

int		ft_stock_file_infos(t_ls *list)
{
	list->next = NULL;
	return (0);
}
