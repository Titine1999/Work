#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:29:41 by dvalenti          #+#    #+#              #
#    Updated: 2017/11/10 22:27:55 by dvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc

CFLAGS= -Wall -Wextra -Werror -I includes

NAME= libft.a

SRC_FILE=	ft_atoi.c\
			ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_strcat.c\
			ft_strctr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtr.c\
			ft_tolower.c\
			ft_toupper.c

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
