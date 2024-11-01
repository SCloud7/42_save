# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 05:29:00 by ssoukoun          #+#    #+#              #
#    Updated: 2024/06/18 16:57:44 by ssoukoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COMP = gcc -Wall -Wextra -Werror 

MANDATORY_SRC = \
                ft_printex.c    \
				ft_printf.c     \
				ft_putchar_fd.c \
				ft_putnbr_fd.c  \
                ft_putstr_fd.c  \
				ft_ptr.c		\
				ft_putunsnbr_fd.c

OBJ_MANDATORY = ${MANDATORY_SRC:.c=.o}

%.o: %.c
		${COMP} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ_MANDATORY}
		ar rcs ${NAME} ${OBJ_MANDATORY}

clean:
		rm -f ${OBJ_MANDATORY}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re