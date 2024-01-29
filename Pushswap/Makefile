# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2024/01/29 14:35:04 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		push_swap.c			\
		algorithm.c			\
		push_swap_utils.c	\
		stack_utils.c		\
		push_movements.c	\
		rotate_movements.c	\
		reverse_movements.c

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