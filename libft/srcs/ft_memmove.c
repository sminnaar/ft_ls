/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:23:56 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:07:58 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst > src)
	{
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
