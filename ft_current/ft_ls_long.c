/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:27:48 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/14 13:01:17 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>

int		ft_print_long(char *name, char *dir, t_info *t_info)
{
	struct passwd 	*pw;
	struct group	*gw;
	struct stat 	sbuf;
	char 			*final;
	int 			i;
	int				len;

	i = 0;
	if (!(t_info = malloc(sizeof(t_info))))
		perror("t_info: ");
	//ft_ls_null_info(t_info);
	if (stat(ft_strjoin(ft_strjoin(name, "/"), dir), &sbuf) < 0)
		perror("stat: ");
	ft_ls_perm(sbuf, t_info);
	t_info->hlinks = sbuf.st_nlink;
	if (!(pw = getpwuid(sbuf.st_uid)))
		perror("User name: ");
	t_info->owner = ft_strdup(pw->pw_name);
	if (!(gw = getgrgid(sbuf.st_gid)))
		perror("Group name: ");
	t_info->group = ft_strdup(gw->gr_name);
	t_info->bytes = sbuf.st_size;
	t_info->mod_time = ft_strdup(ft_ctime(ctime(&sbuf.st_mtime)));
	t_info->name = dir;
	char 			*out;
	len = (ft_strlen(t_info->perm) + ft_strlen(ft_stoa(t_info->hlinks)) + ft_strlen(pw->pw_name) + ft_strlen(gw->gr_name) + ft_strlen(ft_lltoa(t_info->bytes)) + ft_strlen(t_info->mod_time) + ft_strlen(t_info->name));
	final = (char *)malloc(sizeof(char) * (len + 7));
	final = ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(t_info->perm, ft_stoa(t_info->hlinks)), t_info->owner), t_info->group), ft_lltoa(t_info->bytes)), t_info->mod_time), t_info->name);
	ft_putendl(final);
	free(t_info);
	
//PRINTING

//	ft_putstr(t_info->perm);
//	ft_putchar(' ');
//	ft_putshort(t_info->hlinks);
//	ft_putchar(' ');
//	ft_putstr(t_info->owner);
//	ft_putchar(' ');
//	ft_putstr(t_info->group);
//	ft_putchar(' ');
//	ft_putlongl(t_info->bytes);
//	ft_putchar(' ');
//	ft_putstr(t_info->mod_time);
//	ft_putchar(' ');
//	ft_putstr(t_info->name);
//	ft_putchar('\n');
//	free(t_info);
	return (1);
}
