/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_open_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:09:26 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/23 15:09:41 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_open_a(char *path)
{
	DIR				*mydir;
	struct dirent	*fileinfo;

	mydir = opendir(path);
	while ((fileinfo = readdir(mydir)) != NULL)
	{
		if ((fileinfo->d_name) != NULL)
		{
			ft_putendl(fileinfo->d_name);
		}
	}
	ft_putchar('\n');
	closedir(mydir);
}

