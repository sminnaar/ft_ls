/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:47:32 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:09:34 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_repnew(char *s, int c, int d)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_strdup(s);
	while (new[i] != '\0')
	{
		if (new[i] == c)
			new[i] = d;
		i++;
	}
	return (new);
}
