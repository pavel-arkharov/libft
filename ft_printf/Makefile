# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:21:58 by parkharo          #+#    #+#              #
#    Updated: 2022/09/29 14:41:38 by parkharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror 


NAME = libftprintf.a

SRC_PATH = ./src/

SRCS_FILES =	ft_printf.c \
				printchar.c \
				printfloat.c \
				printpercent.c \
				printpointer.c \
				printsignedint.c \
				printstring.c \
				printhex.c \
				printoctal.c \
				printuint.c \
				utils.c \
				parser.c \
				printbinary.c \
				infinity.c

SRCS=$(addprefix $(SRC_PATH), $(SRCS_FILES))

LIB_SRC_PATH=../libft/
LIB_SRC_FILES=ft_putchar.c \
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
	ft_strsep.c \
	ft_chrsep.c \
	get_next_line.c \
	ft_itoa_base.c \
	ft_itoa_basex.c \
	ft_strup.c \
	ft_uitoa.c \
	ft_countdigits.c \
	ft_luitoa.c \
	ft_luitoa_base.c \
	ft_tabdel.c \
	ft_pow.c \
	ft_sqrt.c 

LIB_SRCS=$(addprefix $(LIB_SRC_PATH), $(LIB_SRC_FILES))

LIB_OBJECT_PATH=./objs/
LIB_OBJECT_FILES=$(LIB_SRC_FILES:.c=.o)
LIB_OBJECTS=$(addprefix $(LIB_OBJECT_PATH), $(LIB_OBJECT_FILES))

OBJECT_PATH=./objs/
OBJECT_FILES = $(SRCS_FILES:%.c=%.o)
OBJECTS=$(addprefix $(OBJECT_PATH), $(OBJECT_FILES))

COMPILE=gcc -Wall -Wextra -Werror

INCLUDES =-I../includes -I../libft
HEADERS_PATH=../includes/
HEADER_FILES=ft_printf.h
HEADERS=$(addprefix $(HEADERS_PATH), $(HEADER_FILES))

COLOR_RESET=\033[0m
COLOR_PENDING=\033[0;33m
COLOR_SUCCESS=\033[0;32m
COLOR_DEFAULT=\033[1;34m

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB_OBJECTS) $(HEADERS)
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@ar rc $(NAME) $(OBJECTS) $(LIB_OBJECTS)
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "                  [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"

$(OBJECT_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJECT_PATH) 2>/dev/null || echo "" > /dev/null
	@$(COMPILE) $(INCLUDES) -c $< -o $@ 

$(LIB_OBJECT_PATH)%.o: $(LIB_SRC_PATH)%.c
	@mkdir $(LIB_OBJECT_PATH) 2>/dev/null || echo "" > /dev/null
	@$(COMPILE) $(INCLUDES) -c $< -o $@

clean:
	@make -C ../libft clean
	@rm -f $(OBJECTS)
	@rm -rf $(OBJECT_PATH)

fclean: clean
	@make -C ../libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
