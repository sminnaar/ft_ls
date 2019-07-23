/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:56:17 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/22 13:11:47 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_puttime(char *time)
{
	int i;

	i = 8;
	if (time[i] == ' ')
	{
		ft_putchar(' ');
		i++;
	}
	while (ft_isdigit(time[i]))
		ft_putchar(time[i]);
	i = 4;
	ft_putchar(' ');
	while (ft_isalpha(time[i]))
		ft_putchar(time[i++]);
	i = 10;
	while (i < 16)
		ft_putchar(time[i++]);
	ft_putstr(" ");
}

void	ft_ls_putpermis(int c)
{
	if (c == '0')
		ft_putstr("---");
	else if (c == '1')
		ft_putstr("--x");
	else if (c == '2')
		ft_putstr("-w-");
	else if (c == '3')
		ft_putstr("-wx");
	else if (c == '4')
		ft_putstr("r--");
	else if (c == '5')
		ft_putstr("r-x");
	else if (c == '6')
		ft_putstr("rw-");
	else if (c == '7')
		ft_putstr("rwx");
}

void	ft_ls_print_mode(unsigned mode)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa_base(mode, 8);
	if (i == 0 && str[i] == '1')
	{
		ft_putchar('-');
		i = 3;
	}
	else
	{
		ft_putchar('d');
		i = 2;
	}
	while (str[i] != '\0')
	{
		ft_ls_putpermis(str[i]);
		++i;
	}
	ft_putchar(' ');
	if (str)
		free(str);
}

void	ft_ls_put_og(t_data *using, int spc, t_flags *flag)
{
	if (using->owner)
		ft_putstr(using->owner);
	if (using->group)
		ft_putstr(using->group);
	if (using->bytes)
		spc = flag->bytes - ft_intlen(using->bytes);
	while (spc > 0)
	{
		ft_putchar(' ');
		--spc;
	}
}

void	ft_ls_long(t_data *using, t_flags *flag)
{
	int spc;

	spc = 4;
	if (using->mode)
		ft_ls_print_mode(using->mode);
	if (using->link)
	{
		spc = flag->linklen - ft_intlen(using->link);
		while (spc > 0)
		{
			ft_putchar(' ');
			--spc;
		}
		ft_putnbr(using->link);

	}
	ft_ls_put_og(using, spc, flag);
	printf("%lld", using->bytes);   //might need printf
	if (using->date)
		ft_ls_puttime(using->date);
}
