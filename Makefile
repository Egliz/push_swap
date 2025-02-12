# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 12:19:41 by emorillo          #+#    #+#              #
#    Updated: 2025/02/12 16:34:46 by emorillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

CLEAR = rm -rf

LIBFT_PATH = include/libft
LIBFTA = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)/include

SRC = lists/lstlast.c lists/new.c lists/add_back.c
OBJS = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) $(CFLAGS) main.c $(OBJS) $(LIBFTA) -o $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

lib:
	make -C $(LIBFT_PATH)

clean:
	$(CLEAR) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(CLEAR) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re lib

