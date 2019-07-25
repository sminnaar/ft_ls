/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:58:09 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/25 11:37:01 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_open(char *path)
{
	DIR				*dir;
	struct dirent	*d;

	dir = opendir(path);

	while ((d = readdir(dir)) != NULL)
	{
		/*if (ft_ls_isdir(d->d_name))
		{
			if (!(file = malloc(sizeof(t_files))))
				perror("Malloc error: ");
			file->dir = d->d_name;
			ft_putendl(file->dir);
		}*/
		if ((d->d_name) != NULL)
		{
			ft_putendl(d->d_name);
		}
	}
	ft_putchar('\n');
	closedir(dir);
}

int		main()
{
		ft_ls_open(".");
		return (0);
}
