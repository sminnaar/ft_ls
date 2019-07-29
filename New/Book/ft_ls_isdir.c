/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_isdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:56:40 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/29 11:08:48 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_isdir(char *name)
/*{
 	struct stat s;

 	if (stat(name, &s) < 0)
	{
		perror("STAT: ");
	}
 	return(S_ISDIR(s.st_mode));
}*/

{
	struct stat s;
	
	if (lstat(name, &s) < 0)
		perror("Stat: ");
	if (S_ISREG(s.st_mode))
	{
		return (0);
	}
	else
	{
		return (S_ISDIR(s.st_mode));
	}
}
/*{
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
}*/
