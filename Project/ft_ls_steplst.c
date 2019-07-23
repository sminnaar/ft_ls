/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_steplst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:27:18 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/22 13:03:35 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_fill(t_data *data, t_flags *flag)
{
	t_data *using;

	using = data;
	if (flag->l > 0)
	{
		ft_putstr("Total: ");
		ft_putnbr(ft_ls_memblock(using));
	}
	while (using != NULL)
	{
		if (using->name && flag->a > 0)
			ft_ls_lstput(using, flag);
		else if (using->name && flag->a == 0 && using->name[0] != '.')
			ft_ls_lstput(using, flag);
		using = using->next;
	}
}

void	ft_ls_info(t_data *using, struct stat *info, t_flags *flag)
{
	struct passwd	*pwd;
	struct group	*group;

	pwd = getpwuid(info->st_uid);
	using->owner = ft_strdup(pwd->pw_name);
	group = getgrgid(info->st_gid);
	using->group = ft_strdup(group->gr_name);
	using->mode = info->st_mode;
	using->link = info->st_nlink;
	using->bytes = info->st_size;
	using->cdate = info->st_mtime;
	using->date = ft_strdup(ctime(&info->st_mtime));
	using->memblock = info->st_blocks;
	if (ft_intlen(using->bytes) > flag->bytes)
		flag->bytes = ft_intlen(using->bytes);
	if (ft_intlen(using->link) > flag->linklen)
		flag->linklen = ft_intlen(using->link);
}

void	ft_ls_filefilter(t_data *data, t_flags *flag, char *dirp)
{
	if (flag->file == 0)
	{
		ft_ls_lstsort(&data, flag);
		ft_ls_fill(data, flag);
		if (flag->r > 0 || flag->t > 0)
			ft_ls_sort_name(&data);
		ft_putendl("");
	}
	else
	{
		dirp[ft_strlen(dirp) - 1] = '\0';
		dirp = ft_strchr(dirp, '/');
		++dirp;
		ft_ls_specific(data, flag, dirp);
	}
}

void	ft_ls_dirstat(struct stat *info, char *dirp, struct dirent *ent, int i)
{
	char *tmp;

	tmp = ft_strjoin(dirp, ent->d_name);
	if (i == 0)
		stat(tmp, info);
	else
	{
		if (dirp[ft_strlen(dirp) - 1] == '/')
			dirp[ft_strlen(dirp) - 1] = '\0';
		stat(dirp, info);
	}
	if (tmp)
		free(tmp);
	if (dirp)
		free(dirp);
}

void	ft_ls_steplst(DIR *dir, t_data *data, t_flags *flag, char *dirp)
{
	t_data			*using;
	t_data			*prev;
	struct dirent	*ent;
	struct stat		*info;

	using = data;
	using->prev = NULL;
	if (!(info = malloc(sizeof(struct stat))))
		ft_ls_quit(3, NULL);
	dirp = ft_ls_dirpath(dirp);
	while ((ent = readdir(dir)) != NULL)
	{
		ft_ls_new_node(&using, &prev);
		ft_ls_dirstat(info, ft_strdup(dirp), ent, flag->file);
		ft_ls_info(using, info, flag);
		using->name = ft_strdup(ent->d_name);
		prev = using;
		using = using->next;
	}
	if (info)
		free(info);
	ft_ls_lstclr(using);
	ft_ls_filefilter(data, flag, dirp);
	if (dirp)
		free(dirp);
}
