# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 17:23:51 by jschneid          #+#    #+#              #
#    Updated: 2022/10/04 13:57:18 by jschneid         ###   ########.fr        #
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
	@echo "\033[34mCompiling minitalk...\033[0m"
	@cp ./libft/libft.a ./
	@echo "\033[33mArchive copied"
	@$(CC) $(FLAGS) $(OBJ_SERVER) -L./libft -lft -o $(SERVER)
	@echo "\033[33mServer created"

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(FLAGS) $(OBJ_CLIENT) -L./libft -lft -o $(CLIENT)
	@echo "\033[33mClient created"
	@echo "\033[32m\033[1m\033[4m--MINITALK SUCCESSFULLY COMPILED--\033[0m"

lib:
	@$(MAKE) -C libft/

clean:
	@make fclean -C libft/
	@/bin/rm -f $(OBJ_SERVER)
	@echo "\033[33mServer objectfile deleted"
	@/bin/rm -f $(OBJ_CLIENT)
	@echo "\033[33mClient objectfile deleted"
	@echo "\033[32m\033[1mMake clean done\033[0m"

fclean: clean
	@/bin/rm -f libft.a
	@/bin/rm -f $(SERVER)
	@echo "\033[33mServer executable deleted"
	@/bin/rm -f $(CLIENT)
	@echo "\033[33mClient executable deleted"
	@echo "\033[32m\033[1mMake fclean done\033[0m"

re: fclean all
	@echo "\033[32m\033[1mMake re done\033[0m"

.PHONY:	all bonus clean fclean re

# text modifiers #
RED =				"\e[31m"
GREEN =				"\e[32m"
YELLOW =			"\e[33m"
RESET =				"\e[0m"

