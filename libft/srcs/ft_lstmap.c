/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:04:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 01:52:09 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *element))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	if (new)
	{
		new = f(lst);
		tmp = new;
		while (lst->next != NULL)
		{
			tmp->next = f(lst->next);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}
