/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/09 17:20:57 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_ls_file(int *flags, char **argv)
{
	t_dirs	*dirs;
	t_info	*list;

ft_putstr("			FILES");
ft_putstr("	[");

	F_SET(*flags, F_0, F_REG);
	dirs = ft_dir_new(*(argv + 1));
	list = dirs->list;
	while (*++argv)
	{
		if (ft_ls_check(*argv) != 1)
			continue;
		else
		{
			if (!list)
				list = ft_dir_add(dirs->last);
			dirs->last = list;
			list->name = ft_strdup(*argv);
			lstat(list->name, &list->s_stat);
			ft_dir_form(flags, dirs);
			/* list = !(*flags & F_F) ? dirs->last->next : list->next; */
			list = list->next;
		}
	}
	/* ft_list_print(dirs); */
	if (!(*flags & F_F))
		ft_sorts(flags, dirs);
	ft_prints(flags, dirs);
	ft_sort_clean(dirs);
	F_SET(*flags, F_REG, F_0);
/* ft_putendl("			LS_FILE END"); */
//ft_putendl("	[void]");
//ft_putendl("-----------------------------------");
}

int		ft_ls_check(char *path)
{
	t_stat	s_stat;

/* ft_putendl("			LS_CHECK"); */
/* ft_putendl("-----------------------------------"); */
	if (lstat(path, &s_stat) < 0)
		return (0);
	if ((s_stat.st_mode & S_IFMT) == S_IFREG)
		return (1);
	if ((s_stat.st_mode & S_IFMT) == S_IFDIR)
		return (2);
/* ft_putendl("			LS_CHECK END"); */
/* ft_putendl("-----------------------------------"); */
	return (0);
}

char	*ft_ls_path(char *path, char *d_name)
{
	int		i;
	int		len;
	char	*temp;

/* ft_putendl("			LS_PATH"); */
/* ft_putendl("-----------------------------------"); */
	i = 0;
	len = ft_strlen(path) + ft_strlen(d_name);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (*path)
		temp[i++] = *path++;
	if (temp[i - 1] == '/')
		temp[i] = '/';
	else
		temp[i++] = '/';
	while (*d_name)
		temp[i++] = *d_name++;
	temp[i] = '\0';
/* ft_putendl("			LS_PATH END"); */
/* ft_putendl("-----------------------------------"); */
	return (temp);
}

int		main(int argc, char **argv)
{
	int		flags;
	int		i;
	int		j;

//ft_putendl("-----------------------------------");
//ft_putendl("			INIT");
//ft_putendl("-----------------------------------");
	/* i = -1; */
/* ft_putendl("PARAMS"); */
/* while (argv[++i]) */
/* { */
/* ft_putstr("["); */
/* ft_putnbr(i); */
/* ft_putstr("]"); */
/* ft_putstr("	"); */
/* ft_putendl(argv[i]); */
/* } */

	i = 0;
	i = ft_flags(&flags, argv);
	if ((argc - i) > 1)
		flags |= F_M;
	if (!argv[i])
	{
		ft_dirs(&flags, ".");
//ft_putendl("-----------------------------------");
//ft_putendl("			END");
//ft_putendl("-----------------------------------");
		return (1);
	}
	j = i - 1;
	ft_errors(&flags, argv + j);
	ft_ls_file(&flags, argv + j);
	while (argv[++j])
	{
		if (ft_ls_check(argv[j]))
		{
			int errsv = errno;
			ft_putstr("ERROR_");
			if (errsv == EACCES)
			{
				ft_putendl("EACCES");
				ft_putendl("Permission denied (POSIX.1-2001).");
			}
			if (errsv == EISDIR) 
			{
				ft_putendl("EISDIR");
				ft_putendl("Is a directory (POSIX.1-2001).");
			}
			/* if (errsv == EISNAM) */
			/* { */
			/* 	ft_putendl("EISNAME"); */
			/* 	ft_putendl("Is a named type file."); */
			/* } */
			if (errsv == ELOOP)
			{
				ft_putendl("ELOOP");
				ft_putendl("Too many levels of symbolic links (POSIX.1-2001).");
			}
			if (errsv == EMLINK)
			{
				ft_putendl("EMLINK");
				ft_putendl("Too many links (POSIX.1-2001).");
			}
			if (errsv == ENAMETOOLONG)
			{
				ft_putendl("ENAMETOOLONG");
				ft_putendl("Filename too long (POSIX.1-2001)."); 
			}
			if (errsv == ENOENT)
			{
				ft_putendl("ENOENT");
				ft_putendl("No such file or directory (POSIX.1-2001).");
			}
			if (errsv == ENOMEM)
			{
				ft_putendl("ENOMEM");
				ft_putendl("Not enough space/cannot allocate memory (POSIX.1-2001).");
			}
			if (errsv == ENOTDIR)
			{
				ft_putendl("ENOTDIR");
				ft_putendl("Not a directory (POSIX.1-2001).");
			}
			if (errsv == EROFS)
			{
				ft_putendl("EROFS");
				ft_putendl("Read-only filesystem (POSIX.1-2001).");
			}
		if (ft_ls_check(argv[j]) == 2)
			ft_dirs(&flags, argv[j]);
	}
//ft_putendl("-----------------------------------");
//ft_putendl("			END");
//ft_putendl("-----------------------------------");
	return (1);
}
}







/* {{{TITLE
 *
 * EACCES          Permission denied (POSIX.1-2001).
 * EISDIR          Is a directory (POSIX.1-2001).
 * EISNAM          Is a named type file.
 * ELOOP           Too many levels of symbolic links (POSIX.1-2001). 
 * EMLINK          Too many links (POSIX.1-2001).
 * ENAMETOOLONG    Filename too long (POSIX.1-2001).
   ENOENT          No such file or directory (POSIX.1-2001).
   ENOMEM          Not enough space/cannot allocate memory
                       (POSIX.1-2001).
   ENOTDIR         Not a directory (POSIX.1-2001).
    EROFS           Read-only filesystem (POSIX.1-2001).
 
 }}} */

















