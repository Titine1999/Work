# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 16:26:25 by dvalenti          #+#    #+#              #
#    Updated: 2017/07/26 19:30:06 by dvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR= ar rc

SRC_DIR= ./srcs

SRC_FILE= \
		  ft_putchar.c\
		  ft_putstr.c\
		  ft_strcmp.c\
		  ft_swap.c	

OBJ= $(SRC_FILE:.c=.o)

SRC= $(addprefix $(SRC_DIR)/,$(SRC_FILE))

all: $(NAME)

$(NAME): 
	 $(CC) $(CFLAGS) -c $(SRC)
	 $(AR) $(NAME) $(SRC)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all
