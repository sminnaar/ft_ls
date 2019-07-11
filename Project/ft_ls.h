/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:07:38 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/11 17:55:03 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/includedes/libft.h"

# include <dirent.h>
# include <stdlib.h>

# define LS_FLAGS "l, R, a, r and t"

typedef struct	s_flags
{
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
}				t_flags;
