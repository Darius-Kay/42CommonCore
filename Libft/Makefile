# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakaymak <dakaymak@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 15:18:55 by dakaymak          #+#    #+#              #
#    Updated: 2025/10/21 20:34:39 by dakaymak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_memcmp.c ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_isascii.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_strchr.c ft_strlcat.c ft_strrchr.c ft_strnstr.c ft_strlcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_strdup_fstf.c ft_itoa.c ft_strmapi.c ft_striteri.c
SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ_B = $(SRC_B:%.c=%.o)
OBJECTS = $(SRC:%.c=%.o)
AR = ar rcs

.PHONY:		all clean fclean re

all : $(NAME) bonus

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME) $(OBJ_B)
	$(AR) $(NAME) $(OBJ_B)

clean :
	rm -f $(OBJECTS) $(OBJ_B)

fclean : clean
	rm -f $(NAME)

re : fclean all
