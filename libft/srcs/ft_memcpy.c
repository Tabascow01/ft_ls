/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:09:21 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 01:54:33 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	void	*ret;

	ret = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (ret);
}
