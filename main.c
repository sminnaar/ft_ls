/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:42:38 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/08 13:52:34 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <dirent.h>

int	main()
{
	dirp = opendir(".");
	if (dirp == NULL)
		return (ERROR);
	len = strlen(ft_ls);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_namlen == len && strcmp(dp->d_name, ft_ls) == 0)
		{
			(void)closedir(dirp);
			return (FOUND);
		}
	}
	(void)closedir(dirp);
	return (NOT_FOUND);
}
