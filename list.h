/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:09:36 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/08 15:28:47 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __list_h__
# define __list_h__

# include "libft/includes/libft.h"
# include <stdlib.h>

typedef struct s_link
{
	char			*str;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

t_link	*add_link(t_link *link, char *str);
void	print_list(t_link *link);

#endif
