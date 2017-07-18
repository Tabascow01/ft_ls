#include "ft_ls.h"

int		ft_stock_ent(t_ent *list, struct dirent *entity)
{
	int		newid;

	newid = list->id;
	if (newid > 0)
	{
		while (list->next)
		{
			list = list->next;
			newid++;
		}
		list->next = ft_init_ent();
		list->next->dir_ent = entity;
		list->next->path = ft_strnew(ft_strlen(list->path));
		list->next->path = ft_memcpy(list->next->path, list->path, ft_strlen(list->path));
		list = list->next;
	}
	list->name = ft_strnew(list->dir_ent->d_namlen);
	list->name = ft_memcpy(list->name, list->dir_ent->d_name, list->dir_ent->d_namlen);
	list->type = list->dir_ent->d_type;
	list->id = newid + 1;
	return (1);
}

int		ft_stock_name(t_ent *list, struct dirent *entity)
{
	if (list->dir_ent != NULL)
	{
		if (ft_stock_ent(list, entity))
			return (1);
	}
	return (0);
}
