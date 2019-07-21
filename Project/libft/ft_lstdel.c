/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:30:21 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/20 16:36:50 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*holder;
	t_list	*next;

	holder = *alst;
	if (del != NULL)
	{
		while (holder != NULL)
		{
			next = holder->next;
			del(holder->content, holder->content_size);
			free(holder);
			holder = next;
		}
		*alst = NULL;
	}
}
