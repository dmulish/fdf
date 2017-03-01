# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 15:39:34 by dmulish           #+#    #+#              #
#    Updated: 2017/02/28 20:46:09 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRCS = 

BINS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc $(FLAGS) $(BINS)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all
