# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2024/08/28 12:17:16 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
NAMEBONUS=pipex_bonus
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		pipex.c					\
		path.c					\
		errors_and_free.c

OBJ=$(FT:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) -o $(NAME) ./libft/libft.a

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ) 

	make -C libft/ clean
fclean: clean
	rm -rf $(NAME)

	make -C libft/ fclean
re: fclean $(NAME)
