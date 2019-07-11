/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:00:30 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/11 15:06:33 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_new_node(t_data **using, t_data **prev)
{
	if (!using)
	{
		*using = ft_memalloc(sizeof(t_data));
		(*using)->prev = *prev;
		(*prev)->next = *using;
	}
	else
		(*using)->prev = NULL;
}
