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

void	error_noexist()
{
	ft_putendl_fd("{tmp} repo does not exist [match -> option]", 2);
	exit(-1);
}

void	error_usage()
{
	ft_putendl_fd("usage: ls [-lRart] [file ...]", 2);
	exit(-1);
}

void	error_illegal_option(t_ls *list, int argc)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putstr_fd(list->option, 2);
	ft_putchar_fd('\n', 2);
	if (argc > 3)
		error_usage();
	else
		exit(-1);
}
