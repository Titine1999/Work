#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:29:41 by dvalenti          #+#    #+#              #
#    Updated: 2018/04/07 22:01:44 by dvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc -Wall -Werror -Wextra

HEADER= includes

LIBA= -L./libft/ -lft -lm -L./libqt/ -lqt

CFLAGS= -lmlx -framework OpenGL -framework AppKit -O3

CHEADER= -I $(HEADER)

NAME= fdf

SRC_FILE=	fdf.c \
			init.c\
			parsing.c\
			utility.c\

SRC= $(addprefix src/,$(SRC_FILE))

OBJ = $(SRC:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			make -C ./libqt
			@echo "\033[32mCOMPILATION: LIBFT\033[0m"
			@$(CC) $(CFLAGS) $(CHEADER) $(OBJ) $(LIBA) -o $(NAME)
			@echo "* * COMPILATION FINISHED * *"

%.o: %.c
			@$(CC)  -c $< -o $@
			@echo "\033[32mCREATION: .o\033[0m"

clean:
			@rm -f $(OBJ)
			@echo "\033[31mSUPRESSION: .o\033[0m"
			@make -C ./libft clean
			@echo "\033[31mSUPRESSION: libft/.o\033[0m"

fclean: 	clean
			@rm -f $(NAME)
			@echo "\033[31mSUPRESSION: executable\033[0m"
			@make -C ./libft fclean

re: fclean all
