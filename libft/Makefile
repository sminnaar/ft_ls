# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/19 15:17:25 by sminnaar          #+#    #+#              #
#    Updated: 2019/09/11 13:50:53 by sminnaar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

INC_DIR = ./incs

SRC_DIR = srcs/

OBJ_DIR = build/

SRC =	ft_printf_.c \
		ft_printf_format.c \
		ft_printf_slash.c \
		ft_printf_spec.c \
		ft_printf_specprint.c \
		ft_putlongl.c \
		ft_putshort.c \
		ft_lltoa.c \
		get_next_line.c \
		ft_itoa_base.c \
		ft_intlen.c \
		ft_nl.c \
		ft_dupdelstr.c \
		ft_repnew.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_cntwrd.c \
		ft_getchar.c \
		ft_getchar_fd.c \
		ft_getstr.c \
		ft_getstr_fd.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_iswht.c \
		ft_itoa.c \
		ft_stoa.c \
		ft_lltoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memccpy.c \
		ft_memalloc.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_striter.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \

OBJ = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Object files created"
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) Compiled"
	@ranlib $(NAME)
	@echo "$(NAME) Indexed"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJ))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@clang $(FLAG) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) and build Cleaned"

re: fclean all

del: fclean
	@rm -f libft.h.gch
	@rm -f *.out

.PHONY: all, clean, fclean, re, del
