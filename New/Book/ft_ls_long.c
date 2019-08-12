/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:27:48 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/12 16:29:38 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>

int		ft_print_long(char *name, char *dir)
{
	struct passwd 	*pw;
	struct group	*gw;
	t_info			*t_info;
	struct stat 	sbuf;

	if (!(t_info = malloc(sizeof(t_info))))
		perror("t_info: ");
	stat(ft_strjoin(ft_strjoin(name, "/"), dir), &sbuf);
	ft_ls_perm(sbuf, t_info);
	t_info->hlinks = sbuf.st_nlink;
	pw = getpwuid(sbuf.st_uid);
	t_info->owner = pw->pw_name;
	gw = getgrgid(sbuf.st_gid);
	t_info->group = gw->gr_name;
	t_info->bytes = sbuf.st_size;
	t_info->mod_time = ft_ctime(ctime(&sbuf.st_mtime));
	t_info->name = dir;
	
//PRINTING

	ft_putstr(t_info->perm);
	ft_putchar(' ');
	ft_putshort(t_info->hlinks);
	ft_putchar(' ');
	ft_putstr(t_info->owner);
	ft_putchar(' ');
	ft_putstr(t_info->group);
	ft_putchar(' ');
	ft_putlongl(t_info->bytes);
	ft_putchar(' ');
	ft_putstr(t_info->mod_time);
	ft_putchar(' ');
	ft_putstr(t_info->name);
	ft_putchar('\n');
	return (1);
}
