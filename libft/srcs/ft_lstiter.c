/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:03:47 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 01:51:57 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *element))
{
	t_list *list;

	if (lst != NULL)
	{
		list = lst;
		while (list != NULL)
		{
			f(list);
			list = list->next;
		}
	}
}
