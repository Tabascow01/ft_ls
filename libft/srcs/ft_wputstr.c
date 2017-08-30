/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:25:29 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 02:10:16 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wputstr(wchar_t *wstr)
{
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	while (wstr[i] != '\0')
		bytes += ft_wputchar(wstr[i++]);
	return (bytes);
}
