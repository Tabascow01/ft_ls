#include "ft_ls.h"

int		ft_get_dir(t_ls *list)
{
	DIR				*directory;
	struct dirent	*dir_ent;
	size_t			size;

	size = ft_strlen(list->default_dir);
	if (list->pathname == NULL)
	{
		list->pathname = ft_strnew(size);
		list->pathname = ft_memcpy(list->pathname, list->default_dir, size);
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
