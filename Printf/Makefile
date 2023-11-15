# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 12:15:32 by fsantill          #+#    #+#              #
#    Updated: 2023/11/15 17:54:52 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		ft_printf.c	\
		ft_printf_utils.c

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