/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:48:55 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:08:53 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_putlongl(long long nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
}
