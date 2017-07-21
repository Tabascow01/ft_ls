
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
	t_ent	*entity;

	printf("len_m[%d]\n",max_len);
	if (list->entity->name == NULL && list->entity->type == 0)
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
						&& entity->name[0] != '.')
				{
					printf("id {%d} - ",entity->id);
					printf("type {%d} - ",entity->type);
					printf("option {%s} - ", list->option);
					printf("path{%s} - ",entity->path);
					if (entity->file_stat != NULL)
						printf("fstat_Ok - ");
					printf("name{%s}\n",entity->name);
				}
				entity = entity->next;
			}
			list = list->next;
			printf("\n");
		}
		return (1);
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
