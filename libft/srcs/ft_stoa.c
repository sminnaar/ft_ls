/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:24:07 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/11 12:28:09 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_stoa(short n)
{
	char	out[12];
	char	*new;
	long	x;
	size_t	i;

	if (n == -32767)
		return (ft_strdup("-32767"));
	else if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0)
		x = n * -1;
	else
		(x = n);
	i = 0;
	while (x > 0)
	{
		out[i++] = (x % 10) + 48;
		x /= 10;
	}
	if (n < 0)
		out[i++] = '-';
	out[i] = '\0';
	if (!(new = ft_strnew(ft_strlen(out))))
		return (NULL);
	return (new = ft_strcpy(new, ft_strrev(out)));
}
