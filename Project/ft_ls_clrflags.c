/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_clrflags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:32:33 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/21 13:35:56 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_clrflags(t_flags *flag)
{
	flag->a = 0;
	flag->R = 0;
	flag->r = 0;
	flag->t = 0;
	flag->l = 0;
	flag->file  = 0;
	flag->bytes = 0;
	flag->linklen = 0;
}
