/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lspaceflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:32:30 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 01:51:18 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lspaceflag(t_flags *list)
{
	char	*newarg;
	char	*tmp;

	newarg = ft_strnew((int)ft_strlen(list->args) + 1);
	newarg = ft_strcpy(newarg, " ");
	tmp = list->args;
	newarg = ft_strcat(list->args, newarg);
	list->args = ft_reallocf(newarg, 0);
	ft_strdel(&tmp);
}
