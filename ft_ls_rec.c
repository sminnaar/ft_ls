/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_rec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:06:47 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/12 14:27:50 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <dirent.h>

DIR	*ft_ls_rec(DIR *direct)
{
	DIR				*cur;
	struct dirent	*dp;

	cur = opendir(".");
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
			if ((strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..")))
			{
			ft_ls_rec(++cur);
			if (cur == NULL)
				break ;
			}
		}
	}
	closedir(cur);
	return (cur);
}
