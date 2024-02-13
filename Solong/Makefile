# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2024/02/13 19:24:23 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Imlx
FT=		so_long.c				\
		so_long_utils.c			\
		errors_and_free.c

OBJ=$(FT:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -Llibft/ -lft

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

## For Linux:
## sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
## %.o: %.c
##	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
## $(NAME): $(OBJ)
##	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
