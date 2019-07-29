/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:10:15 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/29 12:21:58 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_files
{
	char				*dir;
	struct s_files		*next;
}						t_files;

void	ft_ls_default(char *name);
void	ft_ls_open_arg(char *path);
void	ft_ls_flags(char *flags, char *path);
void	ft_ls_open_a(char *path);
int		ft_ls_isdir(char *name);
void	ft_ls_print(char *name);
void	ft_ls_recur(char *path);

#endif
