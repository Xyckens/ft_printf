# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvieira <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:14:56 by fvieira           #+#    #+#              #
#    Updated: 2022/11/23 13:15:03 by fvieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_printf.c \
	  ft_print_pointer_fd.c \
	  ft_putchar_fd.c \
	  ft_putnbr_fd.c \
	  ft_putnbr_hex_fd.c \
	  ft_putstr_fd.c \
	  ft_putlongnbr_fd.c \

OBJ = $(SRC:.c=.o)
%.o: %.c
	@cc $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) ta feito crl"
	@ranlib $(NAME)
	@echo "$(NAME) ta indexado crl"

clean: 
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
