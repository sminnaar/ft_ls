/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:05:42 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/22 15:28:00 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>

int		main(int ac, char **av)
{
	struct dirent	*dirp;
	struct stat		stat;
	DIR				*dir;

	if (ac != 2)
	{
		printf("Usage: a.out [File]\n");
		return (0);
	}
	if (lstat(av[1], &stat) == -1)
	{
		perror("lstat");
		return (0);
	}
	dir = opendir(av[1]);
	if (S_ISDIR(lstat(dirp->d_name, &stat)))
	{
		
		printf("Next dir %s", dirp->d_name);
	}
	return (0);
}
