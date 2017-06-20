/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:00:46 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 01:51:38 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;

	if (alst == NULL || del == NULL)
		return ;
	list = *alst;
	while (list != NULL)
	{
		del(list->content, list->content_size);
		free(list);
		list = list->next;
	}
	*alst = NULL;
}
