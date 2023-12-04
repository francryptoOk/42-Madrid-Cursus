# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2023/12/04 16:50:40 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		push_swap.c			\
		push_swap_utils.c	\

OBJ=$(FT:%.c=%.o)

all:$(NAME)

$(NAME):$(OBJ) libft/libft.a
	$(CC) $(OBJ) -o $(NAME) -Llibft/ -lft

libft/libft.a:
	make -C libft/

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean
re: fclean $(NAME)