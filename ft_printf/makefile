#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:29:41 by dvalenti          #+#    #+#              #
#    Updated: 2018/03/20 15:55:15 by dvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc -Wall -Werror -Wextra

HEADER= includes

LIBA= -L./libft/ -lft -lm

CFLAGS= -c

CHEADER= -I $(HEADER)

NAME= libftprintf.a

SRC_FILE=	ft_printf.c \
			parsing.c \
			init.c

SRC= $(addprefix src/,$(SRC_FILE))

OBJ = $(SRC:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJ)
			make -C ./libft
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
%.o: %.c
			$(CC) $(CFLAGS) $(CHEADER) $< -o $@

test:		$(NAME)
			$(CC) $(CHEADER) main.c $(NAME) libft/libft.a -o ft_printf

clean:
			rm -f $(OBJ)
			make -C ./libft clean

fclean: 	clean
			rm -f $(NAME)
			make -C ./libft fclean

re: fclean all
