/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lstclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:48:57 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/21 13:53:27 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_lstclr(t_data *data)
{
	t_data	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		if (tmp->date)
			free(tmp->date);
		if (tmp->name)
			free(tmp->name);
		if (tmp->group)
			free(tmp->group);
		if (tmp->owner)
			free(tmp_owner);
		tmp->next = NULL;
		tmp->prev = NULL;
		if (tmp)
			free(tmp);
	}
}
