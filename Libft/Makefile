# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 11:19:51 by fsantill          #+#    #+#              #
#    Updated: 2023/09/25 18:35:33 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
FT=		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c 	\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c

OBJ=$(FT:%.c=%.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

t: $(NAME) testeos.o
	cc testeos.o -o tests -L. -lft

%.o:%.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re:fclean $(NAME)

# flags -Wall, -Werror y -Wextra. Makefile no debe hacer relink.
# Tu Makefile debe contener al menos las normas $(NAME), all, clean, fclean y re.

# crear programas de prueba para tu proyecto, aunque este trabajo
# no será entregado ni evaluado. Te dará la oportunidad de verificar que tu
# programa funciona correctamente durante tu evaluación y la de otros compañeros.
# Y sí, tienes permitido utilizar estas pruebas durante tu evaluación o la de otros compañeros.