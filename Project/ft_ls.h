/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:07:38 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/17 16:45:26 by sminnaar         ###   ########.fr       */
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
	int			file;
	int			bytes;
	int			linklen;
}				t_flags;

typedef struct		s_data
{
	char			*name;
	unsigned		mode;
	int				link;
	char			*owner;
	char			*group;
	char			*date;
	unsigned		cdate;
	long long		bytes;
	int				memblock;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;


