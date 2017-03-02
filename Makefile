# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 15:39:34 by dmulish           #+#    #+#              #
#    Updated: 2017/03/02 20:57:13 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -I includes/ -g

SRCS = srcs/read_map.c	\
	   srcs/main.c

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(BINS) libft/libft.a

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
