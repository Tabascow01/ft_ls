/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:17:33 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:05:55 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*mstr;
	int		i;

	if (str == NULL || f == NULL)
		return (0);
	i = 0;
	mstr = ft_strnew(ft_strlen(str));
	if (mstr == NULL)
		return (NULL);
	while (str[i])
	{
		mstr[i] = f(str[i]);
		i++;
	}
	return (mstr);
}
