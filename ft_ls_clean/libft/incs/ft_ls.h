/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/07 00:23:36 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdarg.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>

# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <limits.h>

# define E_FLAGS -1
# define E_DIRS -2
# define E_PERMS -4
# define E_PRINTS -8

# define F_SET(FLAGS, F_OFF, F_ON) FLAGS = (FLAGS & ~(F_OFF)) | (F_ON);

# define F_0 0

# define F_1 1
# define F_L 2
# define F_G 4
# define F_T 8
# define F_U 16
# define F_R 32
# define F_F 64
# define F_A 128

# define F_RR 256
# define F_D 512
# define F_FF 1024
# define F_GG 2048
# define F_LL 4096
# define F_P 8192
# define F_2 16384
# define F_3 32768

# define F_I 65536
# define F_M 131072
# define F_REG 262144
# define F_O 524288
# define F_5 1048576
# define F_6 2097152
# define F_7 4194304
# define F_8 8388608




#define FT_(x) if (x)\
{\
	int errsv = errno;\
	ft_putstr("ERROR_");\
	if (errsv == EACCES)\
	{\
		ft_putendl("EACCES");\
		ft_putendl("Permission denied (POSIX.1-2001).")\
	}\
	if (errsv == EISDIR) \
	{\
		ft_putendl("EISDIR");\
		ft_putendl("Is a directory (POSIX.1-2001).");\
    }\
	if (errsv == EISNAM)\
	{\
		ft_putendl("EISNAME");\
		ft_putendl("Is a named type file.");\
	}\
	if (errsv == ELOOP)\
	{\
		ft_putendl("ELOOP");\
		ft_putendl("Too many levels of symbolic links (POSIX.1-2001).");\
	}\
	if (errsv == EMLINK)\
	{\
		ft_putendl("EMLINK");\
		ft_putendl("Too many links (POSIX.1-2001).");\
	}\
	if (errsv == ENAMETOOLONG)\
	{\
		ft_putendl("ENAMETOOLONG");\
		ft_putendl("Filename too long (POSIX.1-2001)."); \
	}\
	if (errsv == ENOENT)\
	{\
		ft_putendl("ENOENT");\
		ft_putendl("No such file or directory (POSIX.1-2001).");\
	}\
	if (errsv == ENOMEM)\
	{\
		ft_putendl("ENOMEM");\
		ft_putendl("Not enough space/cannot allocate memory (POSIX.1-2001).");\
	}\
	if (errsv == ENOTDIR)\
	{\
		ft_putendl("ENOTDIR");\
		ft_putendl("Not a directory (POSIX.1-2001).")\
	}\
	if (errsv == EROFS)\
	{\
		ft_putendl("EROFS");\
		ft_putendl("Read-only filesystem (POSIX.1-2001).");\
	}\



typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_form
{
	size_t				grp_len;
	size_t				usr_len;
	size_t				link_len;
	size_t				size_len;
}						t_form;

typedef struct			s_info
{
	char				*name;
	char				*path;
	int				i;
	char				*t;
	t_stat				s_stat;
	struct s_info		*next;
	struct s_info		*prev;
}						t_info;

typedef struct			s_dirs
{
	int					size;
	int					total;
	char				*root;
	t_stat				s_stat;
	t_form				s_form;
	struct s_info		*list;
	struct s_info		*last;
}						t_dirs;

int						main(int argc, char **argv);
int						ft_ls_check(char *path);
char					*ft_ls_path(char *path, char *d_name);
void					ft_ls_file(int *flags, char **argv);

int						ft_flags(int *flags, char **argv);
int						ft_flag_check(int *flags, char flag);
int						ft_flag_check_(int *flags, char flag);

void					ft_dirs(int *flags, char *path);
t_dirs					*ft_dir_new(char *path);
t_info					*ft_dir_add(t_info *list);
int						ft_dir_fill(int *flags, t_dirs *dirs, char *path);
void					ft_dir_form(int *flags, t_dirs *dirs);

void					ft_sorts(int *flags, t_dirs *dirs);
void					ft_sort_lex(int *flags, t_info **sort, t_info *unsort);
void					ft_sort_time(int *flags, t_info **sort, t_info *unsort);
int						ft_sort_comp(int *flags, t_info *list, t_info *unsort);
void					ft_sort_clean(t_dirs *dirs);

int						ft_prints(int *flags, t_dirs *dirs);
void					ft_print_def(int *flags, t_info *dir);
void					ft_print_lst(int *flags, t_dirs *dirs, t_info *dir);
void					ft_print_perm(t_stat *s_stat);
void					ft_print_perms(char *permissions, t_stat *s_stat);

int						ft_errors(int *flags, char **error);
int						ft_error_flag(char *arg);
int						ft_error_perm(int *flags, char *path);
int						ft_error_dir(char *arg);
int						ft_error_print(int *flags, t_dirs *dirs);

void					ft_flag_print(int *flags);
void					ft_list_print(t_dirs *dirs);

#endif
