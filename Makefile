# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:23:51 by jschneid          #+#    #+#              #
#    Updated: 2022/10/04 11:38:27 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

FLAGS = -Wall -Werror -Wextra

SRC_SERVER = server.c

SRC_CLIENT = client.c

LIB = ./libft/libft.a

CC = gcc

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: lib $(SERVER) $(CLIENT)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(SERVER): $(OBJ_SERVER)
	@cp ./libft/libft.a ./
	@$(CC) $(FLAGS) $(OBJ_SERVER) -L./libft -lft -o $(SERVER)
	@echo "\033[32m{Make done}"

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(FLAGS) $(OBJ_CLIENT) -L./libft -lft -o $(CLIENT)
	@echo "make done..."

lib:
	@$(MAKE) -C libft/

clean:
	@make fclean -C libft/
	@/bin/rm -f $(OBJ_SERVER)
	@/bin/rm -f $(OBJ_CLIENT)
	@echo "make fclean done..."

fclean: clean
	@/bin/rm -f libft.a
	@/bin/rm -f $(SERVER)
	@/bin/rm -f $(CLIENT)
	@echo "make fclean done..."

re: fclean all
	@echo "make re done..."

.PHONY:	all bonus clean fclean re

# text modifiers #
RED =				"\e[31m"
GREEN =				"\e[32m"
YELLOW =			"\e[33m"
RESET =				"\e[0m"

