/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:40:10 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/17 16:05:53 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa_base(long int n, int base)
{
	long int		nbr;
	static size_t	i;
	static char		*str;

	nbr = (long int)n;
	i = 0;
	str = ft_strnew(ft_intlen(nbr) + 1);
	str[ft_intlen(nbr)] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		str[i] = '-';
		i++;
	}
	if (nbr >= base)
	{
		free(str);
		ft_itoa_base(nbr / base, base);
	}
	if (nbr % base > 9)
		str[i++] = (char)((nbr % base) + 87);
	else
		str[i++] = (char)((nbr % base) + 48);
	return (str);
}
