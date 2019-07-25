/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:09:11 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/25 17:09:09 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_recur(char *path)
{
	DIR				*dir;
	struct dirent	*d;
	t_files			*file;

	dir = opendir(path);
	if (!(d = readdir(dir)))
		perror("Readdir error: ");
	while ((d->d_name) != NULL && d->d_name[0] != '.')
	{
		//if (ft_ls_isdir(d->d_name))
		//{
			ft_ls_print(d->d_name);
		//}
	}
	if (!(file = malloc(sizeof(t_files))))
		perror("File Malloc: ");
	if (!(d = readdir(dir)))
		perror("Readdir error: ");
	if (!(file = malloc(sizeof(t_files))))
		perror("Files Malloc: ");
	while ((d->d_name) != NULL && d->d_name[0] != '.')
	{
		//if (ft_ls_isdir(d->d_name))
		//{
			ft_ls_print(d->d_name);
			file->dir = d->d_name; 
		//}
	}
	if (ft_ls_isdir(d->d_name))
	{
		path = ft_strjoin(path, d->d_name);
		ft_ls_recur(path);
		file = file->next;
	}
	free(file);
}
