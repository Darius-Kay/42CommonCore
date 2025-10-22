# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 15:18:55 by dakaymak          #+#    #+#              #
#    Updated: 2025/10/22 15:07:42 by dakaymak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -Iincludes
OBJECTS = $(SRCS:%.c=%.o)
FOLDER = srcs/
SRCS = $(addprefix $(FOLDER), $(SRC))
SRC = ft_putnbr_hexa.c ft_nbrsize.c ft_putunbr.c ft_nbrsize_hexa.c ft_putp.c ft_putchar_len.c ft_putstr_len.c ft_putnbr_len.c ft_printf.c ft_strlcpy.c ft_truestrlen.c
.PHONY:		all clean fclean re

all : $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
