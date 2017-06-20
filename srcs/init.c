/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:50:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:14:59 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ft_init_list()
{
	t_ls *list;

	list = ft_memalloc(sizeof(list));
	list->option = 0;
	list->pathname = NULL;
	list->filename = NULL;
	return (list);
}
