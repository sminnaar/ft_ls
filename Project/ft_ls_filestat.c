/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_filestat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:07:14 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/22 14:04:44 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_isfile(char *name)
{
	struct stat tmp;

	return(stat(name, &tmp) == 0);
}

void	ft_ls_free(char *new, char *tmp, DIR *indir)
{
	if (new)
		free(indir->__dd_buf);
	if (tmp)
		free(tmp);
	if (indir)
		free(indir);
}

void	ft_ls_filestat(t_flags *flag, char *name)
{
	DIR		*idir;
	t_data	*file;
	char	*tmp;
	char	*new;
	char	*ptr;

	if (!(file = ft_memalloc(sizeof(t_data))))
		ft_ls_quit(3, NULL);
	tmp = ft_ls_dirpath(name);
	new = ft_ls_dirpath(name);
	tmp[ft_strlen(tmp) - 1] = '\0';
	ptr = ft_strchr(tmp, '/');
	*++ptr = '\0';
	idir = opendir(tmp);
	if (idir == NULL)
		ft_ls_quit(2, name);
	flag->file = 1;
	if (ft_ls_isfile(name))
		ft_ls_steplst(idir, file, flag, new);
	else
		ft_ls_quit(2, name);
	flag->file = 0;
	ft_ls_lstclr(file);
	ft_ls_free(tmp, new, idir);
}
