/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_memblock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:36:36 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/17 12:48:12 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls_memblock(t_data *using)
{
	int	out;

	out = 0;
	while (using != NULL)
	{
		out += using->memblock;
		using = using->next;
	}
	return (out);
}
