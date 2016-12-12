# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#*   Updated: 2016/12/12 16:47:42 by cfatrane         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = srcs

SRC_NAME =	main.c

CPPFLAGS = -I includes/

LDFLAGS = -L./libft/

LFT = -lft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	make -C./libft/
	@echo "Creation of $(NAME) ..."
	$(CC) $(CFLAGS) $(LDFLAGS) $(LFT) $^ -o $@
	@echo "$(NAME) created"

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

clean:
	@make clean -C ./libft/
	@echo "Removal of .o files of $(NAME) ..."
	@rm -f $(OBJ_NAME)
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
