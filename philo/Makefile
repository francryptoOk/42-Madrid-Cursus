# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2024/09/16 13:26:50 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
NAMEBONUS=philo_bonus
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		philo.c					\
		errors_and_free.c

OBJ=$(FT:%.c=%.o)

all:$(NAME)
$(NAME): $(OBJ)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
