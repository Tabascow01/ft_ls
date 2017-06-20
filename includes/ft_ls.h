/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:51:03 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:05:43 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

#include <../libft/includes/libft.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <dirent.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>

typedef struct		s_ls
{
	struct s_ls		*next;
	char			*option;
	char			*str;
}					t_ls;

void	ft_rec(t_ls *list);
void	ft_long(t_ls *list);
void	ft_all(t_ls *list);
void	ft_rev(t_ls *list);
void	ft_time(t_ls *list);

int		ls_core(t_ls *list);

int		ft_vrf_rec(char c);
int		ft_vrf_long(char c);
int		ft_vrf_all(char c);
int		ft_vrf_rev(char c);
int		ft_vrf_time(char c);

int		ft_vrf_option(t_ls *list, char *argv);

t_ls	*ft_init_list();

void	error_illegal_option(t_ls *list);
void	error_usage();
void	error_usage_end();

#endif
