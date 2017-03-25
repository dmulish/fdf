# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 15:39:34 by dmulish           #+#    #+#              #
#    Updated: 2017/03/25 15:41:58 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -I includes/ -g -O3

MLX_FL = -lmlx -framework OpenGL -framework AppKit

SRCS = srcs/rot.c			\
	   srcs/iso.c			\
	   srcs/main.c			\
	   srcs/draw.c			\
	   srcs/key_hook.c		\
	   srcs/read_map.c		\
	   srcs/new_elem.c		\
	   srcs/draw_grid.c		\
	   srcs/bresenham.c		\
	   srcs/zero_angles.c	\

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(MLX_FL) $(BINS) libft/libft.a

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
