/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:00:24 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/17 13:59:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_dir(t_flags flag, char *indir, int argc)
{
	DIR		*ndir;
	t_data	data;

	if (ft_ls_flag_check(flag))
		--argc;
	if (!(data = ft_memalloc(sizeof(t_data))))
		ft_ls_quit(3, NULL);
	if (data == NULL)
		exit(1);
	ndir = opendir(indir);
	if (ndir == NULL)
		ft_ls_quit(2, indir);
	if (argc > 2 && ft_strcmp(".", indir))
		ft_putendl(indir);
	ft_ls_steplst(ndir, data, flag, indir);
	closedir(ndir);
	if (data)
		ft_ls_lstclear(data);
}
