# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#*   Updated: 2016/12/21 14:52:13 by cfatrane         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC  =		ft_printf.c				\
			ft_parse.c				\
			ft_parse_conv.c			\
			ft_parse_flag.c			\
			ft_parse_size.c			\
			ft_parse_precision.c	\
			ft_parse_modif.c		\
			ft_reader.c				\
			ft_write_arg.c			\
			ft_write_string.c		\
			ft_write_pointor.c		\
			ft_write_signed_int.c	\
			ft_write_unsigned_int.c	\
			ft_write_long_int.c		\
			ft_write_octal.c		\
			ft_write_hexa.c			\
			ft_write_char.c			\
			ft_write_flag_zero.c	\
			ft_write_flag_space.c	\
			ft_write_flag_diese.c	\
			ft_write_size.c			\

OBJ = $(SRC:.c=.o)

CPPFLAGS = -I./includes/

LDFLAGS = -L./libft/

LFT = -lft

LIB = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@echo "Creation of $(NAME) ..."
	@$(CC) $(CPPFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@libtool -static -o $(NAME) $(NAME) $(LIB)
	@ranlib $(NAME)
	@echo "$(NAME) created\n"

$(OBJ): $(SRC)
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Removal of .o files of $(NAME) ..."
	@rm -f $(OBJ)
	@echo "Files .o deleted\n"

fclean: clean
	@make fclean -C ./libft/
	@echo "Removal of $(NAME)..."
	@rm -f $(NAME)
	@echo "Binary $(NAME) deleted\n"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
