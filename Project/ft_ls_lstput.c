/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_lstput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:32:53 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/17 15:36:44 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_lstput(t_data *using, t_flags *flag)
{
	if (flag->l > 0)
		ft_ls_long(using, flag);
	ft_putendl(using->name);
}
