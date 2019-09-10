/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:24:07 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:09:40 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_stoa(short n)
{
	char	*nstr;

	if (!(nstr = (char *)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	if (n < 0)
	{
		nstr[0] = '-';
		nstr[1] = '\0';
		nstr = ft_strjoin(nstr, ft_itoa(-n));
	}
	else if (n >= 10)
		nstr = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n >= 0 && n <= 9)
	{
		nstr[0] = n + '0';
		nstr[1] = '\0';
	}
	return (nstr);
}
