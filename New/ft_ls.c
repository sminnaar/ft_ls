/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:58:09 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/23 15:42:42 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_open(char *path)
{
	DIR				*dir;
	struct dirent	*d;
	t_files			*file;

	dir = opendir(path);
	while ((d = readdir(dir)) != NULL && ft_strcmp(d->d_name, ".") && ft_strcmp(d->d_name, ".."))
	{
		if (ft_ls_isdir(d->d_name))
		{
			if (!(file = malloc(sizeof(t_files))))
				perror("Malloc error: ");
			file->dir = d->d_name;
			ft_putendl(file->dir);
		}
		if ((d->d_name) != NULL)
		{
			ft_putendl(d->d_name);
		}
	}
	ft_putchar('\n');
	closedir(dir);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_ls_open(".");
		return (0);
	}
	if (ac > 1 &&  av[1][0] != '-')
	{
		ft_ls_open(av[1]);
		return (0);
	}
	if (ac > 1 && av[1][0] == '-')
	{
		ft_ls_flags(av[1], av[2]);
		return (0);
	}
	else if (ac > 1 && av[2][0] == '-')
	{
		ft_ls_flags(av[2], av[1]);
		return (0);
	}
	return (0);
}
