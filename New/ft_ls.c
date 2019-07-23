/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:58:09 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/23 13:17:32 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_open(char *path)
{
	DIR				*mydir;
	struct dirent	*fileinfo;

	mydir = opendir(path);
	while ((fileinfo = readdir(mydir)) != NULL)
	{
		if ((fileinfo->d_name) != NULL)
		{
			ft_putendl(fileinfo->d_name);
			//ft_putchar('\t');
		}
	}
	ft_putchar('\n');
	closedir(mydir);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_ls_open(".");
		return (0);
	}
	else
	{
		if (av[1][0] == '-')
		{
			ft_getchar(av[1][1]);
			
		}
		ft_ls_open(av[1]);
		return (0);
	}
}
