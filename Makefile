# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#*   Updated: 2017/01/29 17:49:47 by cfatrane         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./srcs/

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
			ft_write_octal.c			\
			ft_write_b.c				\
			ft_write_p.c				\
			ft_write_s.c				\
			ft_write_ws.c				\
			ft_write_uns.c				\
			ft_write_hexa.c				\
			ft_write_non_valid.c		\
			ft_write_flag.c				\
			ft_printf_putnbr_uns.c		\
			ft_printf_nbrlen_uns.c		\
			ft_printf_str.c				\
			ft_caste_sgn.c				\
			ft_caste_uns.c				\

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./objs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LDFLAGS = -L./libft/

LIB = ./libft/libft.a

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

TEMP = .temp.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@ar rc $(TEMP) $(OBJ)
	@libtool -static -o $(NAME) $(TEMP) $(LIB)
	@ranlib $(NAME)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C ./libft/
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME) $(TEMP)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

git:
	@git add .
	@git commit -m "$(NAME)"
	@git push

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
