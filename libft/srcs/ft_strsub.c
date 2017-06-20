/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:19:01 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:07:54 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t n)
{
	size_t	i;
	char	*mstr;

	mstr = ft_strnew(n);
	if (mstr == NULL || str == NULL)
		return (0);
	str = str + start;
	i = 0;
	while (n > 0)
	{
		mstr[i] = str[i];
		n--;
		i++;
	}
	return (mstr);
}
