NAME = pipex
SRCS =	main.c $(SRCS_FOLDER)

SRCS_FOLDER =	src/utils.c \
				src/read_input.c \
				src/loop_cmds.c \
				src/manage_fd.c

OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -g

LIBFT = libft.a
LIBFT_HEADER = libft
HEADER = includes
CC = clang

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c -o $@ $< -I $(HEADER) -I $(LIBFT_HEADER)

$(LIBFT):
	$(MAKE) -C libft
	cp libft/libft.a .

clean:
	rm -f $(OBJ) $(LIBFT)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
