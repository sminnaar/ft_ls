/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:58:09 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/25 11:33:34 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_open(char *path)
{
	DIR				*dir;
	struct dirent	*d;
	t_files			*file;

	dir = opendir(path);
	if (!(file = malloc(sizeof(t_files))))
		perror("file");
	while ((d = readdir(dir)) != NULL)
	{
		if (ft_ls_isdir(d->d_name))
		{
			file->dir = d->d_name;
			ft_putendl(file->dir);
		}
		/*if (d->d_name)
		{
			ft_putendl(d->d_name);
		}*/
	}
	closedir(dir);
}

int		main()
{
		ft_ls_open(".");
		return (0);
}
