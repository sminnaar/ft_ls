/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:33:56 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/13 10:04:12 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_perm(struct stat sbuf, t_info *t_info)
{
	ft_memset(t_info->perm, '-', 10);
	if ((sbuf.st_mode & S_IFMT) == S_IFDIR)
		t_info->perm[0] = 'd';
	if ((sbuf.st_mode & S_IFMT) == S_IFREG)
		t_info->perm[0] = '-';
	if ((sbuf.st_mode & S_IFMT) == S_IFCHR)
		t_info->perm[0] = 'c';
	if ((sbuf.st_mode & S_IFMT) == S_IFBLK)
		t_info->perm[0] = 'b';
	if (sbuf.st_mode == 16749)
		t_info->perm[0] = 'l';
	if (sbuf.st_mode & S_IRUSR)
		t_info->perm[1] = 'r';
	if (sbuf.st_mode & S_IWUSR)
		t_info->perm[2] = 'w';
	if (sbuf.st_mode & S_IXUSR)
		t_info->perm[3] = 'x';
	if (sbuf.st_mode & S_IRGRP)
		t_info->perm[4] = 'r';
	if (sbuf.st_mode & S_IWGRP)
		t_info->perm[5] = 'w';
	if (sbuf.st_mode & S_IXGRP)
		t_info->perm[6] = 'x';
	if (sbuf.st_mode & S_IROTH)
		t_info->perm[7] = 'r';
	if (sbuf.st_mode & S_IWOTH)
		t_info->perm[8] = 'w';
	if (sbuf.st_mode & S_IXOTH)
		t_info->perm[9] = 'x';
	t_info->perm[10] = '\0';
}
