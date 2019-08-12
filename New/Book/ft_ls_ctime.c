/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_ctime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:25:17 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/12 16:30:11 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ctime_print(char *t)
{
	int i;

	i = 3;
	while (i <= 14)
	{
		ft_putchar(t[++i]);
	}
}


void	ft_ctime_store(char *t, t_info *t_info)
{
	t_info->mod_time = ft_strsub(t, 4, 12);
/*	int i;
	int j;

	i = 3;
	j = -1;
	while (i <= 14)
	{
		t_info->mod_time[++j] = t[++i];
	}*/
}

char	*ft_ctime(char *t)
{
	t[16] = '\0';
	return ((t + 3));
}
