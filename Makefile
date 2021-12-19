# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 10:27:30 by parkharo          #+#    #+#              #
#    Updated: 2021/12/19 19:51:10 by parkharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -I ./includes

NAME = libft.a

SRCS = ./srcs/

SRC = $(SRCS)*.c

SRC2 = $(wildcard *.o)

$(NAME): 
	@echo "Compiling"
	@$(CC) $(CFLAGS) $(SRC)
	@ar rcs $(NAME) *.o


clean:
	@echo "Deleting .o files..."
	@/bin/rm -f *.o

fclean: clean
	@echo "Cleaning up..."
	@/bin/rm -f $(NAME)

all: $(NAME)

re: fclean all
	@echo "Re-compiling..."
	@echo "OK!"
