# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2023/11/14 15:53:46 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		ft_printf.c	\

OBJ=$(FT:%.c=%.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

t: $(NAME) testeos_printf.o
	cc testeos_printf.o -o testeos_printf -L. -lftprintf

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
tclean: clean fclean
	rm -rf testeos_printf.o
	rm -rf testeos_printf
re: fclean $(NAME)