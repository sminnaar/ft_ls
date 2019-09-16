/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:23:59 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/16 12:24:00 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_error_dir(char *path)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (0);
}
int		ft_error_perm(int *flags, char *path, t_dirs *dir)
{
	(*flags & F_P || *flags & F_REG) ? ft_putendl("") : 0;
	if (*flags & F_P || *flags & F_M)
	{
	ft_putstr_fd(path, 2);
	ft_putendl_fd(":", 2);
	}
	ft_putstr_fd("ls: ", 2);
	(ft_strrchr(path, '/')) ? ft_putstr_fd(ft_strrchr(path, '/') + 1, 2) :
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": Permission denied", 2);
	(dir) ? ft_sort_clean(dir) : NULL;
	(*flags & F_P || *flags & F_REG) ? ft_putendl_fd("", 2) : 0;
	F_SET(*flags, F_0, F_P);
	return (0);
}

/* int	ft_error_perm(int *flags, char *path, t_dirs *dirs) */
/* { */
/* 	if ((*flags & F_P)) */
/* 		ft_putendl(""); */
/* 	if (*flags & F_RR) */
/* 	{ */
/* 		ft_putstr_fd(path, 2); */
/* 		ft_putendl_fd(":", 2); */
/* 	} */
/* 	ft_putstr_fd("ft_ls: ", 2); */
/* 	ft_putstr_fd(ft_strrchr(path, '/') + 1, 2); */
/* 	ft_putstr_fd(": ", 2); */
/* 	perror(""); */
/* 	(dirs) ? ft_sort_clean(dirs) : NULL; */
/* 	return (0); */
/* } */

int	ft_error_flag(char *flag)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(*flag, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("usage: ft_ls [-lRartufgd1oF] [file ...]", 2);
	return (0);
}

int	ft_error_print(int *flags, t_dirs *dirs)
{
	t_info	*list;

	list = (*flags & F_R) ? dirs->last : dirs->list;
	while (list && list->name)
	{
		ft_putstr_fd("ft_ls: ", 2);
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
