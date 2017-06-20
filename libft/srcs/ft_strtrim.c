/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:19:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:08:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *str)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	if (str)
	{
		i = 0;
		j = ft_strlen((char *)str) - 1;
		while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && (i <= j))
			i++;
		while ((str[j] == ' ' || str[j] == '\n' || str[j] == '\t') && (j >= i))
			j--;
		if ((tmp = (char *)malloc(sizeof(char) * (j - i + 2))) == NULL)
			return (0);
		k = 0;
		while (i <= j)
			tmp[k++] = str[i++];
		tmp[k] = '\0';
		return (tmp);
	}
	return (0);
}
