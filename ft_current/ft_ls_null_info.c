/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_null_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:05:07 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/13 12:15:57 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_null_info(t_info *t_info)
{
	ft_bzero(t_info->name, 100);
	t_info->hlinks = 0;
	ft_bzero(t_info->owner, 100);
	ft_bzero(t_info->group, 100);
	t_info->bytes = 0;
	ft_bzero(t_info->mod_time, 12);
	ft_bzero(t_info->final, 100);
}
