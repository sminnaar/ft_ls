/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_steplst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:27:18 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/17 16:53:58 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_fill(t_data *data, t_flags *flag)
{
	t_data *using;

	using = data;
	if (flag->l > 0)
	{
		ft_putstr("Total: ");
		ft_putnbr(ft_ls_memblock(using));
	}
	while (using != NULL)
	{
		if (using->name && flag->a > 0)
			ft_ls_lstput(using, flag);
		else if (using->name && flag->a == 0 && using->name[0] != '.')
			ft_ls_lstput(using, flag);
		using = using->next;
	}
}

void	ft_ls_info(t_data *using, struct stat *info, t_flags *flag)
{
	struct passwd	*pwd;
	struct group	*group;

	pwd = getwpuid(info->st_uid);
	using->owner = ft_strdup(pwd->pw_name);
	group = getgrid(info->st_gid);
	using->group = ft_strdup(grp->gr_name);
	using->mode = info->st_mode;
	using->link = info->st_nlink;
	using->bytes = info->st_size;
	using->cdate = info->st_mtime;
	using->date = ft_strdup(ctime(&info->st_mtime));
	using->memblock = info->st_blocks;
	if (ft_intlen(using->bytes) > flag->bytes)
		flag->bytes = ft_intlen(using->bytes);
	if (ft_intlen(using->link) > flag->linklen)
		flag->linklen = ft_intlen(using->link);
}


