/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:00:15 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:00:35 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_long(t_ls *list)
{
	struct stat		fstat;
	t_ent			*entity;

	entity = list->entity;
	while (entity)
	{
		stat(entity->path, &fstat);
		entity->file_stat = &fstat;
//		printf("fstat{%u}\n",entity->file_stat->st_uid);
		entity = entity->next;
	}
}
