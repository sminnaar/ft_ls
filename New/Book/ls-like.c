/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls-like.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 10:58:23 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/29 17:15:49 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char *modes[] = {
	"---", "--x", "-w-", "-wx",
	"r--", "r-x", "rw-", "rwx"
};

void	printout(char *dir, char *name)
{
	int i;
	int j;
	char perms[10];
	struct stat sbuf;
	char newname[1024];

	sprintf(newname, "%s/%s", dir, name);
	stat(newname, &sbuf);
//	printf("%5lld ", (sbuf.st_size + 1023) / 1024);
	switch (sbuf.st_mode & S_IFMT)
	{
		case S_IFREG:	putchar('-'); break;
		case S_IFDIR:	putchar('d'); break;
		case S_IFCHR:	putchar('c'); break;
		case S_IFBLK:	putchar('b'); break;
		default:		putchar('?'); break;
	}
	*perms = 0;
	for (i = 2; i >= 0; i--)
	{
		j = (sbuf.st_mode >> (i * 3)) & 07;
		strcat(perms, modes[j]);
	}
	if ((sbuf.st_mode & S_ISUID) != 0)
		perms[2] = 's';
	if ((sbuf.st_mode & S_ISGID) != 0)
		perms[5] = 's';
	if ((sbuf.st_mode & S_ISVTX) != 0)
		perms[8] = 't';
	printf("%s%3d %5d/%-5d ", perms, sbuf.st_nlink, sbuf.st_uid, sbuf.st_gid);
	printf("%7lld %.12s ", sbuf.st_size, ctime(&sbuf.st_mtime) + 4);
	printf("%s\n", name);
}

void	list(char *name)
{
	DIR				*dp;
	struct dirent	*dir;
	char			*newname[1024];
	int 			i;
	int 			j;

	i = 0;
	if ((dp = opendir(name)) == NULL)
	{
		fprintf(stderr, "%s: cannot open.\n", name);
		return ;
	}
	while ((dir = readdir(dp)) != NULL)
	{
		if (dir->d_ino == 0)
			continue ;
		if (dir->d_name[0] != '.')
			printout(name, dir->d_name);
		if (ft_ls_isdir(ft_strjoin(ft_strjoin(name, "/"), dir->d_name)) && dir->d_name[0] != '.')
		{
			if (name[ft_strlen(name) -1] == '/')
				newname[i] = ft_strjoin(name, dir->d_name);
			else
				newname[i] = ft_strjoin(ft_strjoin(name, "/"), dir->d_name);
			++i;
		}
	}
	closedir(dp);
	j = 0;
	while (j < i)
	{
		printf("\n%s:\n", newname[j]);
		list(newname[j]);
		++j;
	}
}

int main(int ac, char **av)
{
	struct stat sbuf;

	if (ac < 2)
	{
		list(".");
		return (0);
	}
	while (--ac)
	{
		if (stat(*++av, &sbuf) < 0)
		{
			perror(*av);
			continue ;
		}
		if ((sbuf.st_mode & S_IFMT) == S_IFDIR)
			list(*av);
		else
			printout(".", *av);
	}
	return (0);
}
