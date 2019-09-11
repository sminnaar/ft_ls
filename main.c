/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:09:05 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/11 12:12:12 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/incs/libft.h"
#include <stdio.h>

int main()
{
	long long int x;

	x = 1252869209481832;
	ft_putendl(ft_lltoa(x));
	ft_printf_("\n%l\n", x);
	printf("\n%lld\n", x);
	return (0);
}
