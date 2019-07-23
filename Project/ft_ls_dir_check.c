/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_dir_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 14:35:48 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/22 13:24:46 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls_dir_check(char *dir)
{
	struct stat	s;

	if (stat(dir, &s) == 0)
	{
		if (s.st_mode & S_IFDIR)
			return (1);
		else if (s.st_mode & S_IFREG)
			return (0);
		else
			return (0);
	}
	else
		return (0);
}
