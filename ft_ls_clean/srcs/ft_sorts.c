/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/09 17:21:56 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_sort_clean(t_dirs *dirs)
{
	t_info	*list;
	t_info	*next;

// ft_putendl("			CLEAN");
// ft_putendl("-----------------------------------");
	if (dirs)
	{
		list = dirs->list;
		while (list)
		{
			next = list->next;
			if (list->name)
				free(list->name);
			if (list->path)
				free(list->path);
			free(list);
			list = next;
		}
		free(dirs->root);
		free(dirs);
	}
 /* ft_putendl("			SORT_CLEAN END"); */
 /* ft_putendl("-----------------------------------"); */
}

int		ft_sort_comp(int *flags, t_info *a, t_info *b)
{
	if (*flags & F_T)
	{

		if (a->s_stat.st_mtimespec.tv_sec == b->s_stat.st_mtimespec.tv_sec)
		{
			if (a->s_stat.st_mtimespec.tv_nsec != b->s_stat.st_mtimespec.tv_nsec)
				return (a->s_stat.st_mtimespec.tv_nsec < b->s_stat.st_mtimespec.tv_nsec);
			else
				return (ft_strcmp(a->name, b->name));
		}
		else
			return (a->s_stat.st_mtimespec.tv_sec < b->s_stat.st_mtimespec.tv_sec);
	
		
		
		/* else if (a->s_stat.st_mtimespec.tv_nsec != b->s_stat.st_mtimespec.tv_nsec) */
		/* 	return (a->s_stat.st_mtimespec.tv_nsec < b->s_stat.st_mtimespec.tv_nsec); */
		/* else */
		/* 	return (a->s_stat.st_mtimespec.tv_sec < b->s_stat.st_mtimespec.tv_sec); */

	}
	else if (*flags & F_U)
	{
		if (a->s_stat.st_atimespec.tv_sec == b->s_stat.st_atimespec.tv_sec)
		{
			if (a->s_stat.st_atimespec.tv_nsec != b->s_stat.st_atimespec.tv_nsec)
				return (a->s_stat.st_atimespec.tv_nsec < b->s_stat.st_atimespec.tv_nsec);
			else
				return (ft_strcmp(a->name, b->name));
		}
		else
			return (a->s_stat.st_atimespec.tv_sec < b->s_stat.st_atimespec.tv_sec);
		
		
		/* if (a->s_stat.st_atimespec.tv_sec == b->s_stat.st_atimespec.tv_sec) */
		/* { */
		/* 	if (a->s_stat.st_atimespec.tv_nsec == b->s_stat.st_atimespec.tv_nsec) */
		/* 		return (ft_strcmp(a->name, b->name)); */
		/* } */
		/* else if (a->s_stat.st_atimespec.tv_nsec != b->s_stat.st_atimespec.tv_nsec) */
		/* 	return (a->s_stat.st_atimespec.tv_nsec < b->s_stat.st_atimespec.tv_nsec); */
		/* else */
		/* 	return (a->s_stat.st_atimespec.tv_sec < b->s_stat.st_atimespec.tv_sec); */

	}
	return (ft_strcmp(a->name, b->name));
}

t_dirs *ft_sort_merge(int *flags, t_dirs *dirs)
{
t_info *list;
t_info *temp;
t_info *next;
t_info *tail;
int insize;
int nmerges;
int listsize;
int nextsize;
int i;
insize = 1;

	while (insize)
	{
		list = dirs->list;
		dirs->list = NULL;
		tail = NULL;
		nmerges = 0;
		while (list)
		{
			++nmerges;
			next = list;
			listsize = 0;
			i = 0;
			while (i < insize)
			{
				listsize++;
				next = next->next;
				if (!next)
					break;
				i++;
			}
			nextsize = insize;
			while (listsize > 0 || (nextsize > 0 && next))
			{
				/* decide whether next element of merge comes from p or q */
				if (listsize == 0)
				{
					/* p is empty; e must come from q. */
					temp = next;
					next = next->next;
					nextsize--;
				}
				else if (nextsize == 0 || !next)
				{
					/* q is empty; e must come from p. */
					temp = list;
					list = list->next;
					listsize--;
				}
				else if (ft_sort_comp(flags, list, next) <= 0)
				{
					/* First element of p is lower (or same);
					 * * e must come from p. */
					temp = list;
					list = list->next;
					listsize--;
				}
				else
				{
					/* First element of q is lower; e must come from q. */
					temp = next;
					next = next->next;
					nextsize--;
				}
				/* add the next element to the merged list */
				if (tail)
					tail->next = temp;
				else
					dirs->list = temp;
				temp->prev = tail;
				tail = temp;
			}
			/* now p has stepped `insize' places along, and q has too */
			list = next;
		}
		/* dirs->list->prev = tail; */
		if (tail)
		{
			tail->next = NULL;
			dirs->last = tail;
		}
		if (nmerges <= 1)
			break;
		insize *= 2;
	}
	return (dirs);
}

void	ft_sorts(int *flags, t_dirs *dirs)
{

// ft_putendl("			SORT");
// ft_putendl("-----------------------------------");
	dirs = ft_sort_merge(flags, dirs);

 /* ft_putendl("			SORT END"); */
 /* ft_putendl("-----------------------------------"); */
}


