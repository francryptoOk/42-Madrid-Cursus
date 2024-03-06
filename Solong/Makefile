# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2024/03/06 14:56:39 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
NAMEBONUS=so_long_bonus
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		so_long.c				\
		map_check.c				\
		args_utils.c			\
		move_utils.c			\
		move_player.c			\
		errors_and_free.c

OBJ=$(FT:%.c=%.o)

BONUS=	so_long_bonus.c			\
		map_check_bonus.c		\
		args_utils_bonus.c		\
		move_utils_bonus.c		\
		move_player_bonus.c		\
		errors_and_free_bonus.c

OBJBONUS=$(BONUS:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx_opengl_20191021
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) ./libft/libft.a ./minilibx_opengl_20191021/libmlx.a

bonus:$(NAMEBONUS)

$(NAMEBONUS): $(OBJBONUS)
	make -C ./libft
	make -C ./minilibx_opengl_20191021
	$(CC) $(OBJBONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAMEBONUS) ./libft/libft.a ./minilibx_opengl_20191021/libmlx.a

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ) $(OBJBONUS)
	make -C libft/ clean
	make -C minilibx_opengl_20191021/ clean
fclean: clean
	rm -rf $(NAME) $(NAMEBONUS)
	make -C libft/ fclean
	make -C minilibx_opengl_20191021/ clean
re: fclean $(NAME) $(NAMEBONUS)

## For Linux:
## sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
## %.o: %.c
##	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
## $(NAME): $(OBJ)
##	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
