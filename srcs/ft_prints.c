/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/11 12:18:22 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_print_perms(char *permissions, t_stat *s_stat)
{
	if (s_stat->st_mode & S_IRUSR)
		permissions[1] = 'r';
	if (s_stat->st_mode & S_IWUSR)
		permissions[2] = 'w';
	if (s_stat->st_mode & S_IXUSR)
		permissions[3] = 'x';
	if (s_stat->st_mode & S_IRGRP)
		permissions[4] = 'r';
	if (s_stat->st_mode & S_IWGRP)
		permissions[5] = 'w';
	if (s_stat->st_mode & S_IXGRP)
		permissions[6] = 'x';
	if (s_stat->st_mode & S_IROTH)
		permissions[7] = 'r';
	if (s_stat->st_mode & S_IWOTH)
		permissions[8] = 'w';
	if (s_stat->st_mode & S_IXOTH)
		permissions[9] = 'x';
}

void	ft_print_perm(int *flags, t_stat *s_stat)
{
	char	permissions[12];

	ft_memset(permissions, '-', 11);
	if ((s_stat->st_mode & S_IFMT) == S_IFDIR)
		permissions[0] = 'd';
	else if ((s_stat->st_mode & S_IFMT) == S_IFREG)
		permissions[0] = '-';
	else if ((s_stat->st_mode & S_IFMT) == S_IFCHR)
		permissions[0] = 'c';
	else if ((s_stat->st_mode & S_IFMT) == S_IFBLK)
		permissions[0] = 'b';
	else if ((s_stat->st_mode & S_IFMT) == S_IFLNK)
		permissions[0] = 'l';
	else if ((s_stat->st_mode & S_IFMT) == S_IFSOCK)
		permissions[0] = 's';
	else if ((s_stat->st_mode & S_IFMT) == S_IFIFO)
		permissions[0] = 'p';
	ft_print_perms(permissions, s_stat);
	permissions[10] = ' ';
	permissions[11] = '\0';
	(*flags & F_I) ? ft_printf_("%l ", s_stat->st_ino) : NULL;
	ft_printf_("%s", permissions);
}

void	ft_print_def(int *flags, t_info *list)
{
	char	path[PATH_MAX];

	ft_bzero(path, PATH_MAX);
	if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK && (*flags & F_L))
		readlink(list->path, path, PATH_MAX);
	ft_printf_("%s", list->name);
	if (*flags & F_FF)
	{
		if (ft_ls_check(list->path) == 2)
			ft_printf_("/");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK)
			ft_printf_("@ -> %s", path);
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFIFO)
			ft_printf_("|");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFSOCK)
			ft_printf_("=");
		else if (list->s_stat.st_mode & S_IXUSR)
			ft_printf_("*");
	}
	else if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK && (*flags & F_L))
		ft_printf_(" -> %s", path);
	ft_printf_("\n");
}

void	ft_print_lst(int *flags, t_dirs *dirs, t_info *l)
{
	t_passwd	*s_pwd;
	t_group		*s_grp;

	ft_print_perm(flags, &l->s_stat);
	ft_printf_("%.%x ", dirs->s_form.link_len, l->s_stat.st_nlink);
	if (!(*flags & F_O))
	{
		if ((s_pwd = getpwuid(l->s_stat.st_uid)) != NULL)
			ft_printf_("%.%s  ", dirs->s_form.usr_len, s_pwd->pw_name);
		else
			ft_printf_("%.%d  ", dirs->s_form.usr_len, l->s_stat.st_uid);
	}
	if (!(*flags & F_G))
	{
		if ((s_grp = getgrgid(l->s_stat.st_gid)) != NULL)
			ft_printf_("%.%s  ", dirs->s_form.grp_len, s_grp->gr_name);
		else
			ft_printf_("%.%d  ", dirs->s_form.grp_len, l->s_stat.st_gid);
	}
	ft_printf_("%.%d", dirs->s_form.size_len, l->s_stat.st_size);
	(*flags & F_U) ? (ft_printf_("%s ", l->t =
	ft_strsub(ctime(&l->s_stat.st_atime), 3, 13))) :
	ft_printf_("%s ", l->t = ft_strsub(ctime(&l->s_stat.st_mtime), 3, 13));
	ft_print_def(flags, l);
	free(l->t);
}

int		ft_prints(int *flags, t_dirs *dirs)
{
	t_info	*list;

	(*flags & F_REG && !(*flags & F_P)) ? (ft_printf_("\n")) : NULL;
	if ((*flags & F_M))
		(*flags & F_P) ? ft_printf_("\n%s:\n", dirs->root) :
			ft_printf_("%s:\n", dirs->root);
	else if (*flags & F_RR)
		(*flags & F_P) ? ft_printf_("\n%s:\n", dirs->root) :
			ft_printf_("%s:\n", dirs->root);
	if (*flags & F_L && dirs->cool)
		ft_printf_("%s %d\n", "total", dirs->total);
	F_SET(*flags, F_0, F_P);
	list = (*flags & F_R) ? dirs->last : dirs->list;
	while (list && list->name && dirs->cool)
	{
		if (!(*flags & F_A) && list->name[0] == '.')
		{
			list = (*flags & F_R) ? list->prev : list->next;
			continue;
		}
		(*flags & F_1) ? ft_print_def(flags, list) : 0;
		(*flags & F_L) ? ft_print_lst(flags, dirs, list) : 0;
		list = (*flags & F_R) ? list->prev : list->next;
	}
	return (1);
}
