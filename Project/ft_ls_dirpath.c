/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_dirpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:54:19 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/17 13:59:45 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_ls_dirpath(char *indir)
{
	char	*path;
	char	*temp;

	path = NULL;
	temp = NULL;
	if (indir[0] != "." && indir[1] != "/")
	{
		path = ft_strjoin("./", indir);
	}
	else if (path == NULL)
	{
		path = ft_strdup(indir);
	}
	if (path[ft_strlen[path] - 1] != '/')
	{
		temp = path;
		path = ft_strjoin(temp, "/");
		if (temp)
			free(temp);
	}
	return (path);
}
