/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:15:54 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:03:43 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	unsigned char	chr;
	char			*strtmp;

	chr = (unsigned char)c;
	strtmp = NULL;
	if (str)
	{
		strtmp = (char *)str;
		while (*strtmp != '\0' && *strtmp != chr)
			strtmp++;
		if (*strtmp != (char)chr)
			return (0);
		else
			return ((char *)strtmp);
	}
	return (strtmp);
}
