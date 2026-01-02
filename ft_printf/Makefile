# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szaarour <szaarour@student.42beirut.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/29 12:24:53 by szaarour          #+#    #+#              #
#    Updated: 2025/12/29 12:24:53 by szaarour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS = ft_convert.c \
ft_printf.c \
ft_putanything/ft_putchar.c \
ft_putanything/ft_putnbr.c \
ft_putanything/ft_putstr.c \
ft_putanything/ft_putunbr.c \
ft_putanything/ft_puthex.c \
ft_putanything/ft_putptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
