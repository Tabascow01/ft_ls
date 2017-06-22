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

void	ft_init_ls(t_ls *list)
{
	ft_get_dir(list);
}

t_ls	*ft_init_list()
{
	t_ls *list;

	list = ft_memalloc(sizeof(list));
	list->option = 0;
	list->pathname = NULL;
	list->dirname = NULL;
	list->filename = NULL;
	list->default_dir = ".";
	return (list);
}
