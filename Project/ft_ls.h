/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:07:38 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/22 14:46:10 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H_
# define _FT_LS_H_

# include "libft/includes/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <sys/types.h>

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

void				ft_ls_new_node(t_data **using, t_data **prev);
int					ft_ls_flag_check(t_flags *flag);
int					ft_ls_memblock(t_data *using);
void				ft_ls_arg(char **av, t_flags *flag, int ac, int i);
void				ft_ls_flags(t_flags *flag, char *dirp);
t_flags				*ft_ls_argflags(char *ag, t_flags *flag);
void				ft_ls_flagdir(int ac, t_flags *flag, char **av);
void				ft_ls_clrflags(t_flags *flag);
void				ft_ls_dir(t_flags *flag, char *indir, int argc);
int					ft_ls_dir_check(char *dir);
char				*ft_ls_dirpath(char *indir);
int					ft_ls_isfile(char *name);
void				ft_ls_filestat(t_flags *flag, char *name);
int					ft_ls_flag_check(t_flags *flag);
void				ft_ls_puttime(char *time);
void				ft_ls_putpermis(int c);
void				ft_ls_print_mode(unsigned mode);
void				ft_ls_put_og(t_data *using, int spc, t_flags *flag);
void				ft_ls_long(t_data *using, t_flags *flag);
void				ft_ls_lstclr(t_data *data);
void				ft_ls_lstput(t_data *using, t_flags *flag);
void				ft_ls_rev_sort(t_data **data);
void				ft_ls_datesort(t_data **data);
void				ft_ls_rdatesort(t_data **data);
void				ft_ls_lstsort(t_data **data, t_flags *flag);
int					ft_ls_memblock(t_data *using);
void				ft_ls_new_node(t_data **using, t_data **prev);
int					ft_ls_quit(int error, char *str);
int					ft_ls_filter(char * name, t_flags *flags);
void				ft_ls_change_path(t_flags *flag, char *dirp);
void				ft_ls_re(char *repath, char *tmp, struct dirent *dir, t_flags *flag);
void				ft_ls_recur(t_flags *flag, char *path);
void				ft_ls_sort_name(t_data **data);
void				ft_ls_sort_switch(t_data **data, t_data *using);
void				ft_ls_specific(t_data *data, t_flags *flag, char *dir);
void				ft_ls_fill(t_data *data, t_flags *flag);
void				ft_ls_info(t_data *using, struct stat *info, t_flags *flag);
void				ft_ls_filefilter(t_data *data, t_flags *flag, char *dirp);
void				ft_ls_dirstat(struct stat *info, char *dirp, struct dirent *data, int i);
void				ft_ls_steplst(DIR *dir, t_data *data, t_flags *flag, char *dirp);

# endif
