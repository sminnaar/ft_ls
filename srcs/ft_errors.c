/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:36:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/10 15:43:22 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_error_dir(char *path)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (0);
}

int	ft_error_perm(int *flags, char *path, t_dirs *dirs)
{
	ft_putendl("");
	if (*flags & F_RR)
	{
		ft_putstr_fd(path, 2);
		ft_putendl_fd(":", 2);
	}
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(ft_strrchr(path, '/') + 1, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	ft_sort_clean(dirs);
	return (0);
}

int	ft_error_flag(char *flag)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(*flag, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("usage: ls [-lRartufgd1oF] [file ...]", 2);
	return (0);
}

int	ft_error_print(int *flags, t_dirs *dirs)
{
	t_info	*list;

	list = (*flags & F_R) ? dirs->last : dirs->list;
	while (list && list->name)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(list->name, 2);
		ft_putendl_fd(": No such file or directory", 2);
		list = (*flags & F_R) ? list->prev : list->next;
	}
	return (0);
}

int	ft_errors(int *flags, char **error)
{
	t_dirs	*dirs;
	t_info	*list;

	if (!(dirs = ft_dir_new(*(error + 1))))
		return (0);
	list = dirs->list;
	while (*++error)
	{
		if (ft_ls_check(*error) != 0)
			continue;
		else
		{
			if (!list)
				list = ft_dir_add(dirs->last);
			dirs->last = list;
			list->name = ft_strdup(*error);
			list = list->next;
		}
	}
	if (!(*flags & F_F))
		ft_sorts(flags, dirs);
	ft_error_print(flags, dirs);
	ft_sort_clean(dirs);
	return (0);
}
