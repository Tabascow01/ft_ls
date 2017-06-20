/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:17:06 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:05:08 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int i;

	i = 0;
	if (str == NULL || f == NULL)
		return ;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
