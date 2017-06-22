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

int		ft_isoption(char *str, t_ls *list)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (str != NULL && str[0] == '-')
	{
		i++;
		list->option = ft_strnew(6);
		while (str[i])
		{
			if (str[i] == 'R' || str[i] == 'r' || str[i] == 't'
					|| str[i] == 'l' || str[i] == 'a')
			{
				list->option[j++] = str[i];
				i++;
			}
			else
			{
				list->option[j++] = str[i];
				list->option[j] = '\0';
				return (0);
			}
		}
		list->option[j] = '\0';
		return (1);
	}
	return (0);
}

int		ft_ispath(char *str, t_ls *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str != NULL && str[0] != '-')
		if ((list->pathname = ft_strdup(str)))
			return (1);
	return (0);
}

int		ft_vrf_option(t_ls *list, char **argv)
{
	if (ft_isoption(argv[1], list))
	{
		if (ft_ispath(argv[2], list))
			return (1);
		else
			return (1);
	}
	else
		if (ft_ispath(argv[1], list))
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
