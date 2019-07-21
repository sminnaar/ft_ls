/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort_switch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:19:35 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/21 15:24:50 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_sort_switch(t_data **data, t_data *using)
{
	t_data *next;
	t_data *prev;
	t_data *tmp;

	prev = using->prev;
	next = using->next;
	tmp = next->next;
	if (!prev)
		*data = next;
	else
		prev->next = next;
	if (tmp)
		tmp->prev = using;
	next->next = using;
	next->prev = prev;
	using->prev = next;
	using->next = tmp;
}
