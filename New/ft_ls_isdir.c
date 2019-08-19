/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_isdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:56:40 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/25 11:32:36 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_isdir(char *name)
{
	struct stat *s;
	
	if (!(s = malloc(sizeof(stat))))
		perror("stat");
	if (lstat(name, s) == 0)
	{
		if (s->st_mode & S_IFDIR)
			return (1);
		else if (s->st_mode & S_IFREG)
			return (0);
		else
			return (0);
		
	}
	else
		return (0);
}
	/*if (lstat(name, s)) != -1)
	{
		perror("lstat: ");
		return (0);
	}
	if (s->st_mmode )
	if (s->st_mode & S_IFDIR)
		return (1);
	if (s->st_mode & S_IFREG)
		return (0);
	else
		return (0);
}*/