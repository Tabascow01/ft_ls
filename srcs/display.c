
#include "ft_ls.h"

int		ft_max_len(t_ls *list)
{
	size_t	max_len;
	t_ent	*entity;

	max_len = ft_strlen(list->entity->name);
	while (list)
	{
		entity = list->entity;
		while (entity)
		{
			if (entity->next
					&& max_len < ft_strlen(entity->next->name))
				max_len = ft_strlen(entity->next->name);
			entity = entity->next;
		}
		list = list->next;
	}
	return ((int)max_len);
}

int		ft_display_optcore(t_ls *list, int max_len)
{
	if (!list || !list->entity || !list->option)
		return (0);
	printf("{%d}\n",max_len);
	while (list)
	{
		if (ft_strchr(list->option, 'a'))
			ft_all(list);
		if (ft_strchr(list->option, 'r'))
			ft_rev(list);
		if (ft_strchr(list->option, 't'))
			ft_time(list);
		list = list->next;
	}
	return (0);
}

int		ft_display_smpcore(t_ls *list, int max_len)
{
	t_ent	*entity;
	char	*str;
	char	*smax_len;
	int		i;

	i = 0;
	smax_len = ft_itoa_base(max_len, 10);
	str = ft_strnew(ft_strlen(smax_len) + 3);
	str = ft_strcpy(str, "%");
	str = ft_strjoin(str, smax_len);
	str = ft_strjoin(str, "s");
	if (list->entity == NULL)
		return (0);
	if (list && list->entity)
	{
		while (list)
		{
			entity = list->entity;
			while (entity)
			{
				if (ft_strcmp(entity->name,".")
						&& ft_strcmp(entity->name, "..")
						&& entity->name[0] != '.' && i == 0)
				{
					ft_printf("%s", entity->name);
					i++;
				}
				else if (ft_strcmp(entity->name,".")
							&& ft_strcmp(entity->name, "..")
							&& entity->name[0] != '.' && i > 0)
				{
					ft_printf(str, entity->name);
					i++;
				}
				entity = entity->next;
			}
			list = list->next;
		}
		return (1);
	}
	return (0);
}
