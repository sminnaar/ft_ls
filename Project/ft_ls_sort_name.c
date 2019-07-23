/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:11:30 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/22 13:05:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_sort_name(t_data **data)
{
	t_data	*using;
	t_data	*forward;
	int		swp;

	swp = 1;
	while (swp == 1)
	{
		swp = 0;
		using = *data;
		while (using && using->next)
		{
			forward = using;
			while (forward && forward->next)
			{
				if (ft_strcmp(forward->name, forward->next->name) > 0)
				{
					ft_ls_sort_switch(data, forward);
					swp = 1;
				}
				forward = forward->next;
			}
			using = using->next;
		}
	}
}
