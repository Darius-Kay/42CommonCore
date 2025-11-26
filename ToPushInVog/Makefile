CC=cc
NAME = fractol
DIR	= ./sources
MLXDIR = $(DIR)/MacroLibX/
SRC = /utils/init.c \
	  /utils/color.c \
	  /utils/ft_atof.c \
	  /utils/ft_calloc.c \
	  /utils/fractol_utils.c \
	  /utils/error_management.c \
	  /key_management/update.c \
	  /key_management/keystatus.c \
	  /fractols/balls.c \
	  /fractols/julia.c \
	  /fractols/mendelbrot.c \
	  /fractols/fractol.c \
	  /fractols/fractol_choice.c \
	  # /kleinian/kleinian.c 
SRCS = $(addprefix $(DIR), $(SRC))
HEADER = keycode.h fractol.h kleinian.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -Iincludes
LDFLAGS = $(MLXDIR)libmlx.so -lSDL2 -lm

all:$(MLXDIR)libmlx.so $(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(MLXDIR):
	git clone https://github.com/seekrs/MacroLibX.git sources/MacroLibX -j10 2> /dev/null

$(MLXDIR)libmlx.so: $(MLXDIR)
	make -C sources/MacroLibX/ -j

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	rm -f $(MLXDIR)libmlx.so

fclean: clean
	rm -f $(NAME)
	rm -rf ./sources/MacroLibX

run: all
	./$(NAME) $(ARGS)

run2: all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME) $(ARGS)

re: fclean all

.PHONY: all fclean clean run run2 re
