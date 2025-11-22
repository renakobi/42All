NAME    = fractol
CC      = gcc
MLX_DIR = ./minilibx-linux
CFLAGS  = -Wall -Wextra -Werror -I$(MLX_DIR) -g -march=native -flto -funroll-loops -ffast-math
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -Ofast -march=native -flto -funroll-loops -ffast-math

SRC     = main.c fract_init.c utils.c map.c render.c hooks.c render_julia.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
