NAME		=	fillit
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Ilibft -g
LIBFT		=	-Llibft -lft
SRC			=	blocks.c \
				main.c \
				misc.c \
				normalize.c \
				put_blocks.c \
				validate.c \
				put_blocks_misc.c
OBJ			=	$(SRC:%.c=%.o)

all: DEPS $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c %.h

DEPS:
	make -C libft/

clean:
	make -C libft $@
	rm -f $(OBJ)

fclean: clean
	make -C libft $@
	rm -f $(NAME)

re: fclean all
