/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:49:55 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 12:59:15 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_noexist(t_ls *list)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(list->pathname, 2);
	ft_putendl_fd(": No such file or directory", 2);
	if (!ft_strcmp(list->pathname, list->default_dir))
		exit(-1);
}

void	error_usage()
{
	ft_putendl_fd("usage: ls [-lRart] [file ...]", 2);
	exit(-1);
}

void	error_illegal_option(t_ls *list)
{

	ft_putstr_fd("ls: illegal option -- ", 2);
	if (ft_strlen(list->option) > 1)
		ft_putchar_fd(list->option[ft_strlen(list->option) - 1], 2);
	else
		ft_putstr_fd(list->option, 2);
	ft_putchar_fd('\n', 2);
	error_usage();
}
