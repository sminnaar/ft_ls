/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_set_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:36:19 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/11 15:46:17 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flags	*ft_ls_set_flags(char *arg, t_flags *flags)
{
	size_t i;

	i = 0;
	if (arg == '-')
	{
		while (arg[++i] != '\0')
		{
			if (arg[i] == 'l')
				++flags->l;
			else if (arg[i] == 'R')
				++flags->a;
			else if (arg[i] == 'a')
				++flags->a;
			else if (arg[i] == 'r')
				++flags->r;
			else if (arg[i] == 't')
				++flags->t;
			else
				ft_ls_quit(&arg[i], 1);
		}
	}
}
