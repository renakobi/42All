NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c \
			  chunk_sort.c \
			  chunk_sort_extra.c \
			  chunker.c \
			  free.c \
			  hard_coded.c \
			  hard_coded_extra.c \
			  indexing.c \
			  initialise.c \
			  operations.c \
			  ops2.c \
			  utils.c \
			  ft_split.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
