/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:08:07 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:12:28 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cha;
	char	*r_out;

	cha = c;
	r_out = NULL;
	while (*s)
	{
		if (*s == cha)
			r_out = (char*)s;
		++s;
	}
	if (*s == cha)
		return ((char*)s);
	return (r_out);
}
