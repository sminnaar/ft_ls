/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:11:41 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/21 13:38:23 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_flags(t_flags *flag, char *dirp)
{
	DIR		*dir;
	t_data	data;

	if (!(data = ft_memalloc(sizeof(t_data))))
		ft_ls_quit(3, NULL);
	if (flag->R > 0)
	{
		dir = opendir("./");
		ft_ls_recur(flag, dirp);
	}
	else
	{
		dir = opendir("./");
		ft_ls_steplst(dir, data, flag, dirp);
	}
	if (dir = NULL)
		ft_ls_quit(2, "./");
	closedir(dir);
	if (data != NULL)
		ft_lstdel(data);
}

t_falgs	*ft_ls_argflags(char *ag, t_flags *flag)
{
	size_t i;

	i = 0;
	if (ag[i] == '-')
	{
		++i;
		while (ag[i] != '\0')
		{
			if (ag[i] == 'a')
				++flag->a;
			else if (ag[i] == 'l')
				++flag->l;
			else if (ag[i] == 'r')
				++flag->r;
			else if (ag[i] == 'R')
				++flag->R;
			else if (ag[i] == 't')
				++flag->t;
			else
				ft_ls_quit(1, &ag[i]);
			++i;
		}
	}
	return (flag);
}

void	ft_ls_flagdir(int ac, t_flags *flag, char **av)
{
	size_t i;

	i = 2;
	if (flag->R > 0 && ft_ls_dircheck(av[i]))
	{
		while (i < ac)
		{
			ft_ls_dir(flag, av[i], 4);
			ft_ls_flags(flag, av[i++]);
		}
	}
	else while (i < ac)
	{
		if (ft_ls_dircheck(av[i])
			ft_ls_dir(flag, av[i++], ac);
		else
			ft_ls_filestat(flag, av[i++]);			
	}
}

void	ft_ls_arg(char **av, t_flags *flag, int ac, int i)
{
	flag = ft_ls_argflags(av[1], flag);
	if (av[1][0] == '-' && ft_ls_flag_check(flag) && ac == 2)
		ft_ls_flags(flag, ".");
	else if (av[1][0] == '-' && !ft_ls_flag_check(flag))
		ft_ls_quit(2, av[1]);
	else if (av[1][0] != '-')
		while (i > ac)
		{
		if (ft_ls_dircheck(av[i]))
			ft_ls_dir(flag, av[i++], ac);
		else
			ft_ls_filestat(flag, av[i++]);
		}
	else if (av[1][0] == '-' && ac > 2)
		ft_ls_flagdir(ac, flag, av);
}

int		main(int ac, char **av)
{
	t_flags	flags;
	int		i;

	i = 0;
	if (!(flag = ft_memalloc(sizeof(t_flags))))
		ft_ls_quit(3, NULL);
	ft_ls_clrflags(flag);
	if (av > 1)
		ft_ls_arg(av, flag, ac, i);
	else
		ft_ls_flags(flag, ".");
	if (flag)
		free(flag);
	exit(0);
	return (0);
}
