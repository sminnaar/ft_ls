/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:04:29 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/10 17:05:39 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

void	ft_printf_(char *format, ...);
void	ft_spec(char *spec, va_list list, int width);
void	ft_slash(char id);
void	ft_parse(char *form, va_list list);
void	ft_d(int width, va_list list);
void	ft_l(int width, va_list list);
void	ft_s(int width, va_list list);
void	ft_x(int width, va_list list);
int		ft_format_width(va_list list);
char	*ft_lltoa(long long n);

#endif
