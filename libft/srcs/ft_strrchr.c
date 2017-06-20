/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:18:33 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:07:19 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	char *p;

	p = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			p = (char *)str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (p);
}
