#include "ft_ls.h"

int		ft_get_dir(t_ls *list)
{
	DIR				*directory;
	struct dirent	*dir_ent;

	if (list->pathname == NULL)
	{
		list->pathname = list->default_dir;
		return (1);
	}
	dir_ent = NULL;
	directory = NULL;
	if ((directory = opendir(list->pathname)))
		return (1);
	if ((dir_ent = readdir(directory)))
		return (1);
	return (0);
}

int		ft_get_ls(t_ls *list)
{
	list->next = NULL;
	return (0);
}

int		ft_get_file(t_ls *list)
{
	list->next = NULL;
	return (0);
}
