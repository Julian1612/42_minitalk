# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 11:22:21 by jschneid          #+#    #+#              #
#    Updated: 2022/10/05 13:09:22 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

MANDATORY = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_memcpy.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strchr.c \
ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c \
ft_printf_percent.c ft_printf_characters.c ft_printf_pointer.c \
ft_printf_string.c ft_printf_hexadecimal.c ft_printf_numbers.c ft_printf_utils_00.c \
ft_printf_utils_01.c get_next_line.c get_next_line_bonus.c get_next_line_utils.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

OBJ = $(MANDATORY:.c=.o)
OBJB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[34mCompiling libft...\033[0m"
	@ar r $(NAME) $(OBJ)
	@echo "\033[33mArchive created"
	@echo "\033[32m\033[1m\033[4m--LIBFT SUCCESSFULLY COMPILED--\033[0m"

$(OBJ): $(MANDATORY)
	@cc $(FLASG) -c $(MANDATORY)

clean:
	@/bin/rm -f $(OBJ) $(OBJB)
	@echo "\033[33mAll objectfile deleted"
	@echo "\033[32m\033[1mMake clean done\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[33mArchive deleted"
	@echo "\033[32m\033[1mMake fclean done\033[0m"

re: fclean all
	@echo "\033[32m\033[1mMake re done\033[0m"

bonus: $(OBJ) $(OBJB)
	@ar r $(NAME) $(OBJ) $(OBJB)
	@echo "\033[32m\033[1mMake bonus done\033[0m"

$(OBJB): $(BONUS)
	@cc $(FLASG) -c $(BONUS)

.PHONY:			all bonus clean fclean re
