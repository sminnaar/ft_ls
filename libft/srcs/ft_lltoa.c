/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:23:09 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/11 12:05:49 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_lltoa(long long n)
{
	char	out[20];
	char	*new;
	long	x;
	size_t	i;

	if (n == -922337203685477580)
		return (ft_strdup("-922337203685477580"));
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
