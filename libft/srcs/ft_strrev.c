/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:47:51 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 17:47:52 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strrev(char *s)
{
	char temp;
	char *end;
	char *start;

	if (s)
	{
		start = s;
		end = (s + (ft_strlen(s) - 1));
		while (start < end)
		{
			temp = *start;
			*start++ = *end;
			*end-- = temp;
		}
	}
	return (s);
}
