# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 12:19:41 by emorillo          #+#    #+#              #
#    Updated: 2025/04/11 20:35:40 by emorillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRESH = limpiador

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g 

CLEAR = rm -rf

LIBFT_PATH = include/libft
LIBFTA = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)

SRC = lists.c main.c verifications.c utils.c utils2.c mva.c mvb.c  double_moves.c lists1.c stacks.c
OBJS = $(SRC:.c=.o)

all: lib $(NAME)

$(FRESH):
		@echo "\n Yo soy el $@ "
		@echo "		📥 "

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -I $(LIBFT_INC) -c $< -o $@

lib:
	make -C $(LIBFT_PATH)

clean: limpiador
	$(CLEAR) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(CLEAR) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re lib
