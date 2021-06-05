# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opacaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 14:22:43 by opacaud           #+#    #+#              #
#    Updated: 2021/05/27 14:22:46 by opacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

SRC =		ft_printf_no_point_d_letters.c ft_printf_no_point_d_numbers.c ft_printf_no_point_letters.c ft_printf_no_point_numbers.c ft_printf_no_point_z_letters.c ft_printf_no_point_z_numbers.c \
			ft_printf_point_d_letters.c ft_printf_point_d_numbers.c ft_printf_point_letters.c ft_printf_point_numbers.c ft_printf_point_z_letters.c ft_printf_point_z_numbers.c \
			ft_printf_printable.c ft_printf_spaces_zeroes_letters.c ft_printf_spaces_zeroes_numbers.c ft_printf_utils_letters.c ft_printf_utils_numbers.c ft_printf.c 

OBJ =		${SRC:.c=.o}

all:		${NAME}

${NAME}:	${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY :	all clean fclean re
