/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_specific.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:07:04 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/21 12:10:35 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_specific(t_data *data, t_flags *flag, char *dir)
{
	t_data *using;

	using = data;
	while (using != NULL)
	{
		if (ft_strcmp(dir, using->name) == 0)
		{
			ft_ls_lstput(using, flag);
			break ;
		}
		using = using->next;
	}
}
