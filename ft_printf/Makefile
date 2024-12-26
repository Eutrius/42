# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/25 13:21:22 by jyriarte          #+#    #+#              #
#    Updated: 2024/12/26 14:39:01 by jyriarte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -Iinclude -Ilibft

SOURCES = src/ft_printf.c src/ft_printf_utils.c src/main.c
BONUS = 

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAG = -L$(LIBFT_DIR) -lft

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS:.c=.o)


$(NAME): $(LIBFT) $(OBJECTS)
	$(AR) $@ $^

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS_OBJECTS)
	$(AR) $(NAME) $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_FLAG)


all: $(NAME)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) 
	$(MAKE) -C $(LIBFT_DIR) fclean

test: $(NAME)
	$(CC) $(CFLAGS) -o a.out $(SOURCES) $(LIBFT_FLAG)

re: fclean all

.PHONY: all clean fclean re test

