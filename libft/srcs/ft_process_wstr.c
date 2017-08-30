/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_wstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 01:05:57 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 01:58:59 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_wstr(t_flags *list)
{
	list->bytes = ft_wputstr(list->wargs);
	ft_return_wsize(list);
	ft_wstrdel(&list->wargs);
	if (list->digit != NULL)
		ft_strdel(&list->digit);
	ft_clear_flags(list);
	return (0);
}

void	ft_process_wstr(t_flags *list)
{
	if (ft_check_flags(list))
	{
		ft_process_flags(list);
		ft_print_wstr(list);
	}
	else
	{
		list->bytes = ft_wputstr(list->wargs);
		ft_return_wsize(list);
		ft_wstrdel(&list->wargs);
		ft_clear_flags(list);
	}
}
