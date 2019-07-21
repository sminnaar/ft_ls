/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lstsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 11:42:45 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/21 12:05:58 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_rev_sort(t_data **data)
{
	t_data	*using;
	t_data	*nextlst;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		using = *data;
		while (using && using->next)
		{
			nextlst = using;
			while (nextlst && nextlst->next)
			{
				if (ft_strcmp(nextlst->name, nextlst->next->name) > 0)
				{
					ft_ls_switchsort(data, nextlst);
					swap = 1;
				}
					nextlst = nextlst->next;
			}
			using = using->next;
		}
	}
}

void	ft_ls_datesort(t_data **data)
{
	t_data	*using;
	t_data	*nextlst;
	int 	swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		using = *data;
		while (using && using->next)
		{
			nextlst = using;
			while (nextlst && nextlst->next)
			{
				if (nextlst->cdate < nextlst->next->cdate)
				{
					ft_ls_switchsort(data, nextlst);
					swap = 1;
				}
				nextlst = nextlst->next;
			}
			using = using->next;
		}
	}
}

void	ft_ls_rdatesort(t_data **data)
{
	t_data	*using;
	t_data	*nextlst;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		using = *data;
		while (using && using->next)
		{
			nextlst = using;
			while (nextlst && nextlst->next)
			{
				if (nextlst->cdate > nextlst->next->cdate)
				{
					ft_ls_switchsort(data, nextlst);
					swap = 1;
				}
				nextlst = nextlst->next;
			}
			using = using->next;
		}

	}
}

void	ft_ls_lstsort(t_data **data, t_flags *flag)
{
	if (flag->t == 0 && flag->r == 0)
		ft_ls_namesort(data);
	else if (flag->t > 0 && flag->r == 0)
		ft_ls_datesort(data);
	else if (flag->r > 0 && flag->t == 0)
		ft_ls_rev_sort(data);
	else if (flag->t > 0 && flag->r > 0)
		ft_ls_rdatesort(data);
}
