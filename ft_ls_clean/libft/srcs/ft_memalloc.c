/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:08:56 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 16:07:16 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!(mem = (void *)malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
