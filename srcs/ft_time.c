/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:59:46 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:00:06 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cur_time(char **str)
{
	time_t		curtime;

	(*str) = ft_strnew(sizeof(char) * 26);
	curtime = time(&curtime);
	(*str) = ctime(&curtime);
	printf("time: %s\n", (*str));
	return (0);
}

void	ft_time(t_ls *list)
{
	char *str;

	str = NULL;
	ft_cur_time(&str);
	list->next = NULL;
}
