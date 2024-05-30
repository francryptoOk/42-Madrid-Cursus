# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2024/05/30 16:54:02 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
NAMEBONUS=so_long_bonus
CC=gcc
CFLAGS=-Wall -Werror -Wextra
MLX_FLAGS=-Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT_FLAGS=-Llibft -lft
FT=			so_long.c				\
			map_check.c				\
			args_utils.c			\
			move_utils.c			\
			move_player.c			\
			errors_and_free.c

OBJ=$(FT:%.c=%.o)

FTBONUS=	so_long_bonus.c			\
			map_check_bonus.c		\
			args_utils_bonus.c		\
			move_utils_bonus.c		\
			move_player_bonus.c		\
			errors_and_free_bonus.c

OBJBONUS=$(FTBONUS:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS)

bonus:$(NAMEBONUS)

$(NAMEBONUS): $(OBJBONUS)
	make -C ./libft
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $(NAMEBONUS) $(OBJBONUS) $(MLX_FLAGS) $(LIBFT_FLAGS)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ) $(OBJBONUS)
	make -C libft/ clean
	make -C minilibx-linux/ clean
fclean: clean
	rm -rf $(NAME) $(NAMEBONUS)
	make -C libft/ fclean
	make -C minilibx-linux/ fclean
re: fclean $(NAME) $(NAMEBONUS)