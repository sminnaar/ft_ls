# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 13:52:45 by sminnaar          #+#    #+#              #
#    Updated: 2019/09/11 13:52:48 by sminnaar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project file
NAME		= ft_ls

# Project builds and dirs
SRCDIR		= ./srcs/
SRCNAMES	= ft_dirs.c \
			  ft_errors.c \
			  ft_flags.c \
			  ft_ls.c \
			  ft_prints.c \
			  ft_sorts.c \

SRC			= $(addprefix $(SRCDIR), $(SRCNAMES))
BUILDDIR	= ./build/
BUILDOBJS	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR		= ./libft/
LIBFT		= ./libft/libft.a
LIBINC		= ./libft/incs

# Optimization and Compiler flags and commands
CC			= clang
CFLAGS		= -Wall -Werror -Wextra

# Main rule
all: $(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR):
	@echo "Compiling: $(NAME)"
	@mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBINC) -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LIBFT)
	@echo "Compiled: $(NAME)"

# Libft rule
$(LIBFT):
	@make -C $(LIBDIR)

# Cleaning up the build files
clean:
	@rm -rf $(BUILDDIR)
	@make -C $(LIBDIR) clean
	@echo "$(NAME) and build Cleaned"

# Getting rid of the project file
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
