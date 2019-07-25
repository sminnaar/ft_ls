/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:41:07 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/25 16:51:49 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_open_arg(char *path)
{
	DIR				*mydir;
	struct dirent	*dir;

	mydir = opendir(path);
	while ((dir = readdir(mydir)) != NULL)
	{
		ft_ls_print(dir->d_name);
		if (ft_ls_isdir(ft_strjoin(path, dir->d_name)))
			ft_ls_recur(ft_strjoin(path, dir->d_name));
	}
	closedir(mydir);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_ls_default(".");
		return (0);
	}
	ft_ls_open_arg(av[1]);
	return (0);
}
