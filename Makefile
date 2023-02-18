# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:21:58 by parkharo          #+#    #+#              #
#    Updated: 2023/02/18 16:51:08 by parkharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME			= libft.a

# Directories for source files and object files
SRC_PATH		= ./srcs/
OBJ_PATH		= ./objs/

# Source files
SRCS_FILES		= $(wildcard $(SRC_PATH)*.c)
SRCS_FILES2		= $(wildcard $(SRC_PATH)ft_printf/*.c)

# Object files
OBJECT_FILES	= $(SRCS_FILES:$(SRC_PATH)%.c=%.o)
OBJECT_FILES2	= $(SRCS_FILES2:$(SRC_PATH)%.c=%.o)
OBJECTS			= $(addprefix $(OBJ_PATH), $(OBJECT_FILES))
OBJECTS			+= $(addprefix $(OBJ_PATH), $(OBJECT_FILES2))

# Compiler and flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

# Includes
INCLUDES		= -I./includes
HEADERS_PATH	= ./includes/
HEADER_FILES	= libft.h
HEADERS			= $(addprefix $(HEADERS_PATH), $(HEADER_FILES))

# Colors for output
COLOR_RESET		= \033[0m
COLOR_DELETE	= \033[0;31m
COLOR_PENDING	= \033[0;33m
COLOR_SUCCESS	= \033[0;32m

all: $(NAME)

pre:
	@echo "$(NAME)			[$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"

$(NAME): pre $(OBJECTS) $(HEADERS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "			[$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "			[$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(COLOR_DELETE)Deleting object files...$(COLOR_RESET)"
	@rm -rf $(OBJ_PATH)
	@echo "			[$(COLOR_SUCCESS)OK$(COLOR_DEFAULT)]"

fclean: clean
	@echo "$(COLOR_DELETE)Removing library...$(COLOR_RESET)"
	@rm -f $(NAME)
	@echo "			[$(COLOR_SUCCESS)OK$(COLOR_DEFAULT)]"

re: fclean all

.PHONY: all clean fclean re