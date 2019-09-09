/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:16:28 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/03 17:24:52 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_list_print(t_dirs *dirs)
{
	int		i;
	t_info	*list;

	i = 0;
	list = dirs->list;
	printf("------------------------------------------\n");
	printf("dirs			[%p]\n", dirs);
	printf("&dirs->list		[%p]\n", &dirs->list);
	printf("dirs->list		[%p]\n", dirs->list);
	printf("dirs->size		[%d]\n", dirs->size);
	printf("dirs->total		[%d]\n", dirs->total);
	printf("dirs->root		[%s]\n", dirs->root);
	printf("dirs->s_form.grp_len	[%zu]\n", dirs->s_form.grp_len);
	printf("dirs->s_form.usr_len	[%zu]\n", dirs->s_form.usr_len);
	printf("dirs->s_form-.link_len	[%zu]\n", dirs->s_form.link_len);
	printf("dirs->s_form.size_len	[%zu]\n", dirs->s_form.size_len);
	printf("&dirs->last		[%p]\n", &dirs->last);
	printf("dirs->last		[%p]\n", dirs->last);
	printf("------------------------------------------\n");
	while (list)
	{
		printf("-------------------------------------------\n");
		printf("[%d]			[%p]\n", i, list);
		/* printf("list->root		[%s]\n", list->root); */
		printf("list->name		[%s]\n", list->name);
		printf("list->path		[%s]\n", list->path);
		printf("list->next		[%p]\n", list->next);
		printf("list->prev		[%p]\n", list->prev);
		i++;
		list = list->next;
	}
	printf("------------------------------------------\n");
	/* printf("&dirs->list	[%p]\n", &dirs->list); */
	/* printf("dirs->list	[%p]\n", dirs->list); */
	/* printf("------------------------------------------\n"); */
}
