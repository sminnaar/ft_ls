/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:20:58 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/10 13:28:13 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <dirent.h>

int main(void)
{
	typedef struct s_dir
	{
		DIR*	dp;
		char 	*d_name;
	}			t_dir;
	t_dir	*ptr;

	ptr->dp = opendir(".");
	if (ptr->dp == NULL)
		perror("Cant open root");
	else
	{
		while (ptr)
		{
			ptr = readdir(ptr->dp);
			if (ptr == NULL)
				break;
			ft_putendl(ptr->d_name);	
		}
		closedir(ptr->dp);
	}
	return EXIT_SUCCESS;
}

