/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:23:32 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/22 13:09:17 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls_quit(int error, char *str)
{
	if (error == 1)
	{
		ft_putstr("ft_ls: Illigal flag -- ");
		ft_putendl(str);
		ft_putendl("Usage: ft_ls [l, R, a, r and t] [File...]");
	}
	else if (error == 2)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		perror(" ");
	}
	else if (error == 3)
	{
		ft_putendl("Memory allocation error");
	}
	exit(error);
}
