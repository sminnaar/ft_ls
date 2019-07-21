/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:43:44 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/21 15:06:38 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_filter(char * name, t_flags *flags)
{
	if (flag->a > 0 && ft_strcmp(name, ".") && ft_strcmp(name, ".."))
		return (1);
	else if (flag->a == 0 && name[0] != '.')
		eturn (1);
	else
		return (0);
}

void	ft_ls_change_path(t_flags *flag, char *dirp)
{
	struct dirent	*dir;
	DIR				*tmp;

	tmp = opendir(dirp);
	while (dir = readdir(tmp) != NULL)
	{
		if (ft_ls_dir_check(dir->d_name) && ft_ls_filter(dir->d_name, flag))
			ft_ls_dir(flag, dir->d_name, 4);
	}
	closedir(tmp);
}

void	ft_ls_re(char *repath, char *tmp, struct dirent *dir, t_flags *flag)
{
	if (ft_ls_dir_check(tmp) && ft_ls_filter(dir->d_name, flag))
	{
		free(tmp);
		tmp = ft_strjoin(repath, dir->d_name);
		ft_ls_dir(flag, tmp, 4);
		ft_ls_recur(flag, tmp);
	}
	if (repath)
		free(repath);
	if (tmp)
		free(tmp);
}

void	ft_ls_recur(t_flags *flag, char *path)
{
	DIR				*dirp;
	struct dirent	*dir;
	char			*repath;
	char			*tmp;

	dirp = opendir(path);
	if (dirp == NULL)
		ft_ls_quit(2, path);
	if (!ft_strcmp(path, "."))
		ft_ls_dir(flag, path, 4);
	while (dir = readdir(dirp) != NULL)
	{
		repath = ft_strjoin(path, "/");
		tmp = ft_strjoin(repath, dir->d_name);
		ft_ls_re(repath, tmp, dir, flag);
	}
	closedir(dirp);
}
