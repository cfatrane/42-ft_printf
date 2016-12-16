# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#*   Updated: 2016/12/16 11:35:43 by cfatrane         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./srcs/

SRC_NAME =	ft_printf.c			\
			ft_parse_conv.c		\
			ft_parse_flag.c		\
			ft_reader.c			\
			ft_write_arg.c		\
			ft_write_string.c	\
			ft_write_int.c		\
			ft_write_hexa.c		\
			ft_write_char.c		\

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./objs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CPPFLAGS = -I./includes/

LDFLAGS = -L./libft/

LFT = -lft

LIB = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creation of $(NAME) ..."
	@ar rc $(NAME) $(OBJ)
#	ar -rcT libaz.a $(NAME) $(LIB)
#	@ranlib $(NAME)
	@echo "$(NAME) created\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@make -C ./libft/
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Removal of .o files of $(NAME) ..."
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
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
