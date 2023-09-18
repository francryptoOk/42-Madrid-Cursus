# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 11:19:51 by fsantill          #+#    #+#              #
#    Updated: 2023/09/18 11:18:23 by fsantill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
FT = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c

OBJ = $(FT:%.c=%.o)

ALL:$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

TESTEOS: $(NAME) testeos.o
	cc testeos.o -o tests -L. -lft

%.o: %.c
	cc $(CFLAGS) -c $<

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re:fclean all
	$(NAME)

# flags -Wall, -Werror y -Wextra. Makefile no debe hacer relink.
# Tu Makefile debe contener al menos las normas $(NAME), all, clean, fclean y re.

# crear programas de prueba para tu proyecto, aunque este trabajo
# no será entregado ni evaluado. Te dará la oportunidad de verificar que tu
# programa funciona correctamente durante tu evaluación y la de otros compañeros.
# Y sí, tienes permitido utilizar estas pruebas durante tu evaluación o la de otros compañeros.