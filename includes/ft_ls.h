/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:51:03 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 13:05:41 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

#include <../libft/includes/libft.h>
//#include <>
//#include <>

typedef struct		s_ls
{
	struct s_ls		*next;
	char			option;
	char			*str;
}					t_ls;

int		ls_core(t_ls *list);

int		ft_vrf_option(t_ls *list);

t_ls	*ft_init_list();

void	error_illegal_option(t_ls *list);
void	error_usage();
void	error_usage_end();

#endif
