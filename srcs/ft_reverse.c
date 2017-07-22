/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 14:00:49 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:01:07 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ent_cpy(t_ent *list, t_ent *rev_ent)
{
	t_ent	*prev_ent;
	static int	nbrev;

	if (!list)
		return (0);
	if (nbrev < 1)
	{
		rev_ent = ft_init_ent();
		rev_ent->prev = NULL;
		rev_ent->id = list->id;
		nbrev++;
	}
	else
	{
//		while (rev_ent->next)
//			rev_ent = rev_ent->next;
		prev_ent = rev_ent;
		rev_ent->next = ft_init_ent();
		rev_ent = rev_ent->next;
		rev_ent->prev = prev_ent;
		rev_ent->id = list->id;
	}
	printf("id_cpy[%d]\n",rev_ent->id);
	return (1);
}

void	ft_rev(t_ls *list)
{
	t_ent	*entity;
	t_ent	*rev_ent;

	rev_ent = NULL;
	entity = list->entity;
	while (entity->next)
		entity = entity->next;
	while (entity)
	{
		if (!ent_cpy(entity, rev_ent))
			return ;
		entity = entity->prev;
	}
	printf("rev_ent1[%d]\n",rev_ent->id);
	while (rev_ent)
	{
		printf("rev_ent[%d]\n",rev_ent->id);
		rev_ent = rev_ent->next;
	}
}
