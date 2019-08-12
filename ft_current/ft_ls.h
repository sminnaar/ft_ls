/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:10:15 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/12 16:29:16 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_info
{
	char				*name;
	char				perm[11];
	short				hlinks;
	char				*owner;
	char				*group;
	long				bytes;
	char				*mod_time;

}						t_info;

char	*ft_ctime(char *t);
void	ft_ls_perm(struct stat sbuf, t_info *t_info);
void	ft_ls_default(char *name);
void	ft_ctime_print(char *t);
void	ft_ctime_store(char *t, t_info *t_info);
void	ft_ls_open_arg(char *path);
void	ft_ls_flags(char *flags, char *path);
void	ft_ls_open_a(char *path);
int		ft_ls_isdir(char *name);
void	ft_ls_print(char *name);
void	ft_ls_recur(char *path);
int 	ft_print_long(char *name, char *dir);

#endif
