# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 10:27:30 by parkharo          #+#    #+#              #
#    Updated: 2021/12/19 19:27:21 by parkharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -I ./includes

NAME = libft.a

SRC = ft_putchar.c \
	ft_putstr.c \
	ft_strdup.c \
	ft_strcmp.c \
	ft_strlen.c  \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_putnbr.c \
	ft_atoi.c \
	ft_isspace.c \
	ft_isdigit.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memset.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isalnum.c \
	ft_isprint.c \
	ft_strchr.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_memalloc.c \
	ft_strclr.c \
	ft_strnew.c \
	ft_striteri.c \
	ft_striter.c \
	ft_strdel.c \
	ft_memdel.c \
	ft_putendl.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strsplit.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_iscntrl.c \
	ft_str_is_printable.c \
	ft_calloc.c \
	ft_strndup.c \
	ft_lsttemplate.c \
	ft_lstprint.c \
	ft_lstpush.c \
	ft_lsttail.c \
	ft_printnode.c \
	get_next_line.c

SRC2 = $(SRC:%.c=%.o)

$(NAME): 
	@echo "Compiling"
	@$(CC) $(CFLAGS) $(SRC)
	@ar rcs $(NAME) $(SRC2)


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
