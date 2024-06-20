# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2024/06/20 15:17:06 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
NAMEBONUS=pipex_bonus
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		pipex.c					\
		args_utils.c			\
		errors_and_free.c

OBJ=$(FT:%.c=%.o)

BONUS=	pipex_bonus.c			\
		args_utils_bonus.c		\
		errors_and_free_bonus.c

OBJBONUS=$(BONUS:%.c=%.o)

all:$(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) -o $(NAME) ./libft/libft.a

bonus:$(NAMEBONUS)

$(NAMEBONUS): $(OBJBONUS)
	make -C ./libft
	$(CC) $(OBJBONUS) -o $(NAMEBONUS) ./libft/libft.a

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ) $(OBJBONUS)
	make -C libft/ clean
fclean: clean
	rm -rf $(NAME) $(NAMEBONUS)
	make -C libft/ fclean
re: fclean $(NAME) $(NAMEBONUS)