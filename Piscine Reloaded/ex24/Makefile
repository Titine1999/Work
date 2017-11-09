#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:29:41 by dvalenti          #+#    #+#              #
#    Updated: 2017/11/09 02:28:50 by dvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc

CFLAGS= -Wall -Wextra -Werror -I includes

NAME= libft.a

SRC_FILE=	srcs/ft_putchar.c\
			srcs/ft_strcmp.c\
		  	srcs/ft_strlen.c\
		  	srcs/ft_putstr.c\
		  	srcs/ft_swap.c

OBJ=	ft_putchar.o\
		ft_strcmp.o\
		ft_strlen.o\
		ft_putstr.o\
		ft_swap.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC_FILE)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
