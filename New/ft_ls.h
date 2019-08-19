/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:10:15 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/25 11:41:47 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_files
{
	char		*dir;
}				t_files;

void	ft_ls_open(char *path);
void	ft_ls_flags(char *flags, char *path);
void	ft_ls_open_a(char *path);
int		ft_ls_isdir(char *name);

#endif