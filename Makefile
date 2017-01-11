# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#*   Updated: 2017/01/11 10:41:24 by cfatrane         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_NAME =	ft_printf.c					\
			ft_parse.c					\
			ft_parse_conv.c				\
			ft_parse_flag.c				\
			ft_parse_size.c				\
			ft_parse_precision.c		\
			ft_parse_modif.c			\
			ft_reader.c					\
			ft_write_arg.c				\
			ft_write_c.c				\
			ft_write_wc.c				\
			ft_write_sgn.c				\
			ft_write_sgn_pos.c			\
			ft_write_sgn_neg.c			\
			ft_write_octal.c				\
			ft_write_p.c				\
			ft_write_s.c				\
			ft_write_ws.c				\
			ft_write_uns.c				\
			ft_write_hexa.c				\
			ft_write_double_percent.c	\
			ft_write_non_valid.c		\
			ft_write_flag_zero.c		\
			ft_write_flag_diese.c		\
			ft_write_flag_more.c		\
			ft_write_flag_space.c		\
			ft_printf_putnbr_sgn.c		\
			ft_printf_putnbr_uns.c		\
			ft_printf_putchar.c			\
			ft_printf_puthexa.c			\
			ft_printf_nbrlen_sgn.c		\
			ft_printf_nbrlen_uns.c		\
			ft_printf_putstr.c			\
			ft_printf_strlen.c			\
			ft_caste.c					\

OBJ_PATH = ./objs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CPPFLAGS = -I./includes/

LDFLAGS = -L./libft/

LIB = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

TEMP = temp.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@echo "Creation of $(NAME) ..."
#	@$(CC) $(CPPFLAGS) -c $(SRC)
	@ar rc $(TEMP) $(OBJ)
	@libtool -static -o $(NAME) $(TEMP) $(LIB)
	@ranlib $(NAME)
	@echo "$(NAME) created\n"

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Removal of .o files of $(NAME) ..."
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Files .o deleted\n"

fclean: clean
	@make fclean -C ./libft/
	@echo "Removal of $(NAME)..."
	@rm -f $(NAME) $(TEMP)
	@echo "Binary $(NAME) deleted\n"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
