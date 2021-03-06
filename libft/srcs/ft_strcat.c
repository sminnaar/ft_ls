/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 08:44:04 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:10:03 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *dst;

	dst = s1;
	while (*dst)
		++dst;
	while (*s2)
	{
		*dst = *s2;
		++dst;
		++s2;
		*dst = '\0';
	}
	return (s1);
}
