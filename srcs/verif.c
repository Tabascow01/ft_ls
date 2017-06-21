/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:03:25 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 13:56:31 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_vrf_option(t_ls *list, char *argv)
{
	int i;

	i = 0;
	if (ft_strchr(argv,'R'))
		list->option[i++] = 'R';
	if (ft_strchr(argv, 'l'))
		list->option[i++] = 'l';
	if (ft_strchr(argv, 'a'))
		list->option[i++] = 'a';
	if (ft_strchr(argv, 'r'))
		list->option[i++] = 'r';
	if (ft_strchr(argv, 't'))
		list->option[i++] = 't';
	if (!ft_strcmp(argv, "./"))// TO CHANGE
	list->option[i++] = ' ';
	if (list->option[0] != '\0')
		return (1);
	return (0);
}

int		ft_vrf_rec(char c)
{
	if (c == 'R')
		return (1);
	return (0);
}

int		ft_vrf_long(char c)
{
	if (c == 'l')
		return (1);
	return (0);
}

int		ft_vrf_all(char c)
{
	if (c == 'a')
		return (1);
	return (0);
}

int		ft_vrf_rev(char c)
{
	if (c == 'r')
		return (1);
	return (0);
}

int		ft_vrf_time(char c)
{
	if (c == 't')
		return (1);
	return (0);
}
