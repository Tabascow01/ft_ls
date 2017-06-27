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
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (list->option == NULL && str != NULL && str[0] == '-')
	{
		i = 1;
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
	static int	nbpath;
	t_ls		*begin;

	begin = NULL;
	if (str != NULL && str[0] != '-' && nbpath < 1)
	{
		list->pathname = ft_strnew(ft_strlen(str));
		list->pathname = ft_memcpy(list->pathname, str, ft_strlen(str));
		if(ft_strlen(list->pathname) > 0)
		{
			list->id = nbpath;
			nbpath += 1;
			return (1);
		}
	}
	else if (str != NULL && str[0] != '-' && nbpath > 0)
	{
		begin = list;
		while (list->next)
			list = list->next;
		list->next = ft_init_list();
		list = list->next;
		if (begin->option != NULL)
		{
			list->option = ft_strnew(6);
			list->option = ft_memcpy(list->option, begin->option, ft_strlen(begin->option));
		}
		list->pathname = ft_strnew(ft_strlen(str));
		list->pathname = ft_memcpy(list->pathname, str, ft_strlen(str));
		if (ft_strlen(list->pathname) > 0)
		{
			list->id = nbpath;
			nbpath += 1;
			return (1);
		}
	}
	return (0);
}

int		ft_vrf_option(t_ls *list, char **argv)
{
	int i;

	i = 1;
	if (argv == NULL || argv[1][0] == '\0')
		return (1);
	while (argv[i])
	{
		if (ft_isoption(argv[i], list) && i == 1)
		{
			if (argv[i + 1] != NULL)
			{
				i += 1;
				ft_ispath(argv[i], list);
			}
			else
				return (1);
		}
		else if (!ft_ispath(argv[i], list))
			error_noexist();
		i++;
	}
	return (1);
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
