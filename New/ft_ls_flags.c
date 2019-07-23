/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:37:57 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/23 15:08:39 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_flags(char *flags, char *path)
{
	/*if (++(*flags) == 'l')
		ft_ls_long();
	else if (++(*flags) == 'R')
		ft_ls_recur();
	else if (++(*flags) == 'r')
		ft_ls_rev();*/
	 if (++(*flags) == 'a')
		ft_ls_open_a(path);
	/*else if (++(*flags) == 't')
		ft_ls_time();*/
}
