#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:29:41 by dvalenti          #+#    #+#              #
#    Updated: 2018/04/07 17:58:31 by dvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc

HEADER= libqt.h

CFLAGS= -Wall -Wextra -Werror

CHEADER= -I $(HEADER)

NAME= libqt.a

SRC_FILE=	calc_power.c\
			calc_quaternion.c\
			quaternion.c

OBJ= $(SRC_FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CHEADER) $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
