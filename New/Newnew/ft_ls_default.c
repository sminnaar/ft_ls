/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:42:34 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/25 16:58:37 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_default(char *path)
{
	DIR				*dir;
	struct dirent	*d;

	dir = opendir(path);
	while ((d = readdir(dir)) != NULL)
	{
		if ((d->d_name) != NULL && d->d_name[0] != '.')
			ft_ls_print(d->d_name);
	}
	closedir(dir);
}
