/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/10 15:02:51 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

t_info	*ft_dir_add(t_info *last)
{
	t_info	*new;

	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->name = NULL;
	new->path = NULL;
	new->next = NULL;
	last->next = new;
	new->prev = last;
	return (new);
}

t_dirs	*ft_dir_new(char *path)
{
	t_dirs	*new;

	if (!(new = (t_dirs *)malloc(sizeof(t_dirs))))
		return (NULL);
	new->root = ft_strdup(path);
	if (!(new->list = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->list->name = NULL;
	new->list->path = NULL;
	new->list->next = NULL;
	new->list->prev = NULL;
	new->s_form.grp_len = 0;
	new->cool = 1;
	new->s_form.usr_len = 0;
	new->s_form.size_len = 0;
	new->s_form.link_len = 0;
	new->total = 0;
	new->size = 0;
	new->last = NULL;
	return (new);
}

void	ft_dir_form(int *flags, t_dirs *dirs)
{
	t_info		*last;
	t_passwd	*s_pwd;
	t_group		*s_grp;

	last = dirs->last;
	if (ft_intlen(last->s_stat.st_nlink) > dirs->s_form.link_len)
		dirs->s_form.link_len = ft_intlen(last->s_stat.st_nlink);
	if (!(*flags & F_O))
	{
		if ((s_pwd = getpwuid(last->s_stat.st_uid)) != NULL
			&& ft_strlen(s_pwd->pw_name) > dirs->s_form.usr_len)
			dirs->s_form.usr_len = ft_strlen(s_pwd->pw_name);
		else if (ft_intlen(last->s_stat.st_uid) > dirs->s_form.usr_len)
			dirs->s_form.usr_len = ft_intlen(last->s_stat.st_uid);
	}
	if (!(*flags & F_G))
	{
		if ((s_grp = getgrgid(last->s_stat.st_gid)) != NULL
			&& ft_strlen(s_grp->gr_name) > dirs->s_form.grp_len)
			dirs->s_form.grp_len = ft_strlen(s_grp->gr_name);
		else if (ft_intlen(last->s_stat.st_gid) > dirs->s_form.grp_len)
			dirs->s_form.grp_len = ft_intlen(last->s_stat.st_gid);
	}
	if (ft_intlen(last->s_stat.st_size) > dirs->s_form.size_len)
		dirs->s_form.size_len = ft_intlen(last->s_stat.st_size);
}

int		ft_dir_fill(int *flags, t_dirs *dirs, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	t_info		*list;

	if ((dir = opendir(path)) == NULL)
		return (ft_error_perm(flags, path, dirs));
	list = dirs->list;
	while ((s_dir = readdir(dir)) != NULL)
	{
		if (!list)
			list = ft_dir_add(dirs->last);
		dirs->last = list;
		list->name = ft_strdup(s_dir->d_name);
		list->path = ft_ls_path(path, s_dir->d_name);
		if ((lstat(list->path, &list->s_stat)) == -1)
			dirs->cool = 0;
		dirs->total += list->s_stat.st_blocks;
		(*flags & F_L) ? ft_dir_form(flags, dirs) : NULL;
		list = list->next;
	}
	closedir(dir);
	(!(*flags & F_F)) ? ft_sorts(flags, dirs) : NULL;
	ft_prints(flags, dirs);
	return (1);
}

void	ft_dirs(int *flags, char *path)
{
	t_dirs	*dirs;
	t_info	*list;

	if (!(dirs = ft_dir_new(path)))
		return ;
	if (!(ft_dir_fill(flags, dirs, path)))
		return ;
	if (*flags & F_RR)
	{
		list = (*flags & F_R) ? dirs->last : dirs->list;
		while (list)
		{
			if ((list->name[0] == '.' && list->name[1] == '\0') ||
				((list->name[0] == '.' && list->name[2] == '\0') &&
				list->name[1] == '.'))
			{
				list = (*flags & F_R) ? list->prev : list->next;
				continue;
			}
			else if (ft_ls_check(list->path) == 2)
				ft_dirs(flags, list->path);
			list = (*flags & F_R) ? list->prev : list->next;
		}
	}
	ft_sort_clean(dirs);
}
