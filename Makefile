# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:21:58 by parkharo          #+#    #+#              #
#    Updated: 2023/02/18 13:30:49 by parkharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a

SRC_PATH 		=	./srcs/ft_printf/
SRCS_FILES		=	$(wildcard *.c)
SRCS			=	$(addprefix $(SRC_PATH), $(SRCS_FILES))

LIB_SRC_PATH	=	./srcs/
LIB_SRC_FILES	=	$(wildcard *.c)
LIB_SRCS		=	$(addprefix $(LIB_SRC_PATH), $(LIB_SRC_FILES))

LIB_OBJECT_PATH		=	./srcs/objs/
LIB_OBJECT_FILES	=	$(LIB_SRC_FILES:.c=.o)
LIB_OBJECTS			=	$(addprefix $(LIB_OBJECT_PATH), $(LIB_OBJECT_FILES))

OBJECT_PATH		=	./srcs/ft_printf/objs/
OBJECT_FILES	=	$(SRCS_FILES:%.c=%.o)
OBJECTS			=	$(addprefix $(OBJECT_PATH), $(OBJECT_FILES))

COMPILE			=	gcc -Wall -Wextra -Werror

INCLUDES		=	-I./includes
HEADERS_PATH	=	./includes/
HEADER_FILES	=	libft.h
HEADERS			=	$(addprefix $(HEADERS_PATH), $(HEADER_FILES))

COLOR_RESET		=	\033[0m
COLOR_PENDING	=	\033[0;33m
COLOR_SUCCESS	=	\033[0;32m
COLOR_DEFAULT	=	\033[1;34m

all: $(NAME)

$(NAME): $(LIB_OBJECTS) $(OBJECTS) $(HEADERS)
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@ar rcs $(NAME) $(LIB_OBJECTS) $(OBJECTS) 
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "                  [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"
 
$(OBJECT_PATH)%.o: $(SRCS)
	@mkdir $(OBJECT_PATH) 2>/dev/null || echo "" > /dev/null
	@$(COMPILE) $(INCLUDES) -c $< -o $@ 

$(LIB_OBJECT_PATH)%.o: $(LIB_SRCS)
	@mkdir $(LIB_OBJECT_PATH) 2>/dev/null || echo "" > /dev/null
	@$(COMPILE) $(INCLUDES) -c $< -o $@

clean:
	@echo "Deleting .o files..."
	@rm -f $(LIB_OBJECTS)
	@rm -f $(OBJECTS)
	@rm -rf $(LIB_OBJECT_PATH)
	@rm -rf $(OBJECT_PATH)

fclean: clean
	@echo "Cleaning up..."
	@rm -f $(NAME)

re: fclean all
	@echo "Recompiling..."

.PHONY: clean fclean re all
