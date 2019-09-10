/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:38:03 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:03:52 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_atoi(const char *nptr)
{
	int		out;
	int		p_n;
	size_t	i;

	out = 0;
	p_n = 1;
	i = 0;
	while (ft_iswht(nptr[i]))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			p_n = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		out = out * 10 + nptr[i] - 48;
		i++;
	}
	return ((int)(out * p_n));
}
