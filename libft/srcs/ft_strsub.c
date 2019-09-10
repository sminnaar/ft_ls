/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:10:50 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:12:47 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;

	if (!s || !(nstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		nstr[i] = s[start + i];
		++i;
		nstr[i] = '\0';
	}
	return (nstr);
}
