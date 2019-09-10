/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putshort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:40:19 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 17:50:38 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_putshort(unsigned short nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
}
