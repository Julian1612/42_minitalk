# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:23:51 by jschneid          #+#    #+#              #
#    Updated: 2022/10/02 17:24:57 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

FLAGS = -Wall -Werror -Wextra -g

MANDATORY = client.c server.c

LIB = ./libft/libft.a

CC = gcc

OBJ = $(MANDATORY:.c=.o)

all: lib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

lib:
	@$(MAKE) -C libft/

$(NAME): $(OBJ) lib
	@cp ./libft/libft.a ./
	@$(CC) $(FLAGS) $(OBJ) -L./libft -lft -o $(NAME)
	@echo "make done"

clean:
	@make fclean -C libft/
	@/bin/rm -f $(OBJ)
	@echo "make clean done"

fclean: clean
	@/bin/rm -f libft.a
	@/bin/rm -f $(NAME)
	@echo "make fclean done"

re: fclean all
	@echo "make re done"

.PHONY:	all bonus clean fclean re
