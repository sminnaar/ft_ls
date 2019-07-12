/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:42:38 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/12 14:17:15 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <dirent.h>

DIR *ft_ls_rec(DIR *direct);

int	main()
{
	DIR	*dirp;

	dirp = opendir("./Test");
	ft_ls_rec(dirp);
}


