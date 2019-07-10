/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:34:53 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/10 13:13:11 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef FL_LS_H
//# define FT_LS_H

# include "libft/includes/libft.h"
# include <dirent.h>

typedef struct		s_flags
{
	DIR*			dirp;
	char			*d_name;
	char			*d_flags;
	struct s_flags			*direntp;
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
	char			*d_rev;
	struct s_direct *next;
	struct s_direct *prev;
}					t_dir;

/*typedef struct	s_dir
{
	char	*name;
	char	*owner;
	char	*group;
	char	*date;
}			t_dir;

*/
//#endif
