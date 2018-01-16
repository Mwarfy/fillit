#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anzhan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 20:15:36 by anzhan            #+#    #+#              #
#    Updated: 2018/01/10 19:23:19 by matranch         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =	main.c \
		check_valid.c \
		reader.c \
		stock.c

OUTPUT = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft

LIBFT = libft.a

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OUTPUT)
	@make -C $(LIB_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OUTPUT) $(LIB_DIR)/$(LIBFT)

clean:
	rm -f $(OUTPUT)
	@make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all
