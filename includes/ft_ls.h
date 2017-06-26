/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 12:51:03 by mchemakh          #+#    #+#             */
/*   Updated: 2017/06/20 14:15:07 by mchemakh         ###   ########.fr       */
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
#include <sys/xattr.h>

typedef struct		s_ls
{
	struct s_ls		*next;
	char			*option;
	char			*pathname;
	char			**filename;
	char			**dirname;
	char			*default_dir;
	void			*t_dir;
}					t_ls;

typedef struct		s_dir
{
	struct	s_dir	*next;
	int				dir_id;
	char			*path;
	char			*name;
	char			*rights;
	char			*date;
	char			*user;
	char			*grp;
	void			*t_file;
}					t_dir;

typedef struct		s_file
{
	struct	s_file	*next;
	int				file_id;
	char			*path;
	char			*rights;
//	char			*uid;// ???
	char			*name;
	char			*date;
	char			*size;
	char			*user;
	char			*grp;
}					t_file;

int		ft_get_ls(t_ls *list);
int		ft_get_dir(t_ls *list);
int		ft_get_file(t_ls *list);

int		ft_ispath(char *argv, t_ls *list);
int		ft_isoption(char *argv, t_ls *list);
int		ft_cur_time(char **str);

void	ft_rec(t_ls *list);
void	ft_long(t_ls *list);
void	ft_all(t_ls *list);
void	ft_rev(t_ls *list);
void	ft_time(t_ls *list);

int		ft_vrf_rec(char c);
int		ft_vrf_long(char c);
int		ft_vrf_all(char c);
int		ft_vrf_rev(char c);
int		ft_vrf_time(char c);

int		ls_core(t_ls *list);

int		ft_vrf_option(t_ls *list, char **argv);

void	ft_init_ls(t_ls *list);
t_file	*ft_init_file();
t_dir	*ft_init_dir();
t_ls	*ft_init_list();

void	error_noexist();
void	error_illegal_option(t_ls *list, int argc);
void	error_usage();

#endif
