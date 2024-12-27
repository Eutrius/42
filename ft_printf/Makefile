# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/25 13:21:22 by jyriarte          #+#    #+#              #
#    Updated: 2024/12/27 18:57:43 by jyriarte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -Iinclude

SOURCES = src/ft_printf.c src/ft_printf_utils.c src/ft_putlchar.c src/ft_putlstr.c \
			src/ft_putlmem.c src/ft_putlint.c src/ft_putluint.c src/ft_putlhex.c \
			src/ft_putlnbr_base.c
# BONUS = 

OBJECTS = $(SOURCES:.c=.o)
# BONUS_OBJECTS = $(BONUS:.c=.o)


$(NAME): $(OBJECTS)
	$(AR) $@ $^

# bonus: $(BONUS_OBJECTS)
# 	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  

all: $(NAME)

clean:
	$(RM) $(OBJECTS) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re test

