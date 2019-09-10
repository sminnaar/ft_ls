/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/10 17:59:58 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_ls_file(int *flags, char **argv)
{
	t_dirs	*dirs;
	t_info	*list;

	F_SET(*flags, F_0, F_REG);
	dirs = ft_dir_new(*(argv + 1));
	list = dirs->list;
	while (*++argv)
	{
		if (ft_ls_check(*argv) != 1 && ft_ls_check(*argv) != 4)
			continue;
		if (!list)
			list = ft_dir_add(dirs->last);
		dirs->last = list;
		list->name = ft_strdup(*argv);
		lstat(list->name, &list->s_stat);
		(*flags & F_L) ? ft_dir_form(flags, dirs) : NULL;
		list = list->next;
	}
	if (!(*flags & F_F))
		ft_sorts(flags, dirs);
	ft_prints(flags, dirs);
	ft_sort_clean(dirs);
	F_SET(*flags, (F_REG + F_P), F_0);
}

char	*ft_ls_path(char *path, char *d_name)
{
	char	lpath[PATH_MAX];
	int		i;
	int		len;
	char	*temp;

	if (ft_ls_check(path) == 3)
	{
		readlink(path, ft_memset(lpath, 0, PATH_MAX), PATH_MAX);
		path = lpath;
	}
	i = 0;
	len = ft_strlen(path) + ft_strlen(d_name);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (*path)
		temp[i++] = *path++;
	if (temp[i - 1] == '/')
		temp[i] = '/';
	else
		temp[i++] = '/';
	while (*d_name)
		temp[i++] = *d_name++;
	temp[i] = '\0';
	return (temp);
}

int		ft_ls_check(char *path)
{
	t_stat	s_stat;

	if (lstat(path, &s_stat) < 0)
		return (0);
	if ((s_stat.st_mode & S_IFMT) == S_IFREG)
		return (1);
	if ((s_stat.st_mode & S_IFMT) == S_IFDIR)
		return (2);
	if ((s_stat.st_mode & S_IFMT) == S_IFLNK)
		return (3);
	if ((s_stat.st_mode & S_IFMT) == S_IFCHR)
		return (4);
	return (0);
}

int		main(int argc, char **argv)
{
	char	path[PATH_MAX];
	int		flags;
	int		i;

	if ((argc - (i = ft_flags(&flags, argv)) > 1))
		F_SET(flags, F_0, F_M);
	if (!argv[i--])
	{
		ft_dirs(&flags, ".");
		return (1);
	}
	ft_errors(&flags, argv + i);
	ft_ls_file(&flags, argv + i);
	while (argv[++i])
	{
		if (ft_ls_check(argv[i]) == 2)
			ft_dirs(&flags, argv[i]);
		else if (ft_ls_check(argv[i]) == 3)
		{
			readlink(argv[i], ft_memset(path, 0, PATH_MAX), PATH_MAX);
			ft_dirs(&flags, path);
		}
	}
	return (1);
}
