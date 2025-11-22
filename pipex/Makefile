# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 18:54:03 by rkobeiss          #+#    #+#              #
#    Updated: 2025/09/15 15:26:30 by rkobeiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
cc = gcc
CFLAGS = -Werror -Wextra -Wall -g

SRC = main.c ft_split.c process.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all
