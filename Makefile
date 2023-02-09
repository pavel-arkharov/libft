# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:21:58 by parkharo          #+#    #+#              #
#    Updated: 2023/02/09 11:42:14 by parkharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror 


NAME 			= libft2.a

SRC_PATH 		=	./ft_printf/src/

SRCS_FILES		=	*.c

SRCS			=	$(addprefix $(SRC_PATH), $(SRCS_FILES))

LIB_SRC_PATH	=	./libft/
LIB_SRC_FILES	=	*.c

LIB_SRCS		=	$(addprefix $(LIB_SRC_PATH), $(LIB_SRC_FILES))

LIB_OBJECT_PATH		=	./ft_printf/objs/
LIB_OBJECT_FILES	=	$(LIB_SRC_FILES:.c=.o)
LIB_OBJECTS			=	$(addprefix $(LIB_OBJECT_PATH), $(LIB_OBJECT_FILES))

OBJECT_PATH		=	./ft_printf/objs/
OBJECT_FILES	=	$(SRCS_FILES:%.c=%.o)
OBJECTS			=	$(addprefix $(OBJECT_PATH), $(OBJECT_FILES))

COMPILE			=	gcc -Wall -Wextra -Werror

INCLUDES		=	-I./includes -I./libft
HEADERS_PATH	=	./includes/
HEADER_FILES	=	ft_printf.h
HEADERS			=	$(addprefix $(HEADERS_PATH), $(HEADER_FILES))

COLOR_RESET		=	\033[0m
COLOR_PENDING	=	\033[0;33m
COLOR_SUCCESS	=	\033[0;32m
COLOR_DEFAULT	=	\033[1;34m

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
	@make -C ./libft clean
	@rm -f $(OBJECTS)
	@rm -rf $(OBJECT_PATH)

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
