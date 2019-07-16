/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_rec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:06:47 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/16 12:48:17 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

DIR	*ft_ls_rec(char *direct)
{
	DIR				*cur;
	struct dirent	*dp;
	struct stat		fstat;
	
	int fd;

	//ft_nl();
	cur = opendir(direct);
	//fd = dirfd(cur);
	//ft_putchar('\n');
	//ft_putnbr(fd);
	if (cur == NULL)
		perror("Can't open dir");
	else
	{
		while (cur != NULL)
		{
			dp = readdir(cur);
			if (dp == NULL)
				break ;
			ft_putendl(dp->d_name);
			if (!(strcmp(dp->d_name, ".") && !strcmp(dp->d_name, "..")))		
			{
				lstat(strcat("./", dp->d_name), &fstat);
				if (S_ISDIR(fstat.st_mode))
				{
				ft_ls_rec(ft_strjoin(ft_strjoin(direct, "/"), dp->d_name));
				if (cur == NULL)
					break ;
				}
			}
		}
	}
	closedir(cur);
	return (cur);
}
