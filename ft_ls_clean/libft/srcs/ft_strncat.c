/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:19:20 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:11:42 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *dst;

	dst = s1;
	while (*dst)
		++dst;
	while (*s2 && n)
	{
		*dst = *s2;
		++dst;
		++s2;
		--n;
	}
	*dst = '\0';
	return (s1);
}
