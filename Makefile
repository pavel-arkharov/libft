# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:21:58 by parkharo          #+#    #+#              #
#    Updated: 2023/02/18 14:57:39 by parkharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME 			= libft.a

# SRC_PATH 		=	./srcs/
# SRC2_PATH		=	./srcs/ft_printf/
# SRCS_FILES		=	$(wildcard $(SRC_PATH)*.c)
# SRCS2_FILES		=	$(wildcard $(SRC2_PATH)*.c)

# OBJECT_PATH		=	./objs/
# OBJECT_FILES	=	$(SRCS_FILES:%.c=%.o)
# OBJECT2_FILES	=   $(SRCS2_FILES:%.c=%.o)
# OBJECTS			=	$(addprefix $(OBJECT_PATH), $(OBJECT_FILES))
# OBJECTS			+=  $(addprefix $(OBJECT_PATH), $(OBJECT2_FILES))
# OBJ 			=  $(SRCS_FILES:$(SRCS_PATH)%.c=$(OBJECT_PATH)%.o)
# OBJ 			+=  $(SRCS_FILES2:$(SRCS2_PATH)%.c=$(OBJECT_PATH)%.o)

# COMPILE			=	gcc -Wall -Wextra -Werror

# INCLUDES		=	-I./includes
# HEADERS_PATH	=	./includes/
# HEADER_FILES	=	libft.h
# HEADERS			=	$(addprefix $(HEADERS_PATH), $(HEADER_FILES))

# COLOR_RESET		=	\033[0m
# COLOR_PENDING	=	\033[0;33m
# COLOR_SUCCESS	=	\033[0;32m
# COLOR_DEFAULT	=	\033[1;34m


# all: $(NAME)

# print: 
# 	@echo $(OBJ)

# print2: 
# 	@echo $(SRCS_FILES)
# 	@echo "ASDASDAS"
# 	@echo $(SRCS2_FILES)

# print3: 
# 	@echo $(OBJECTS)

# $(NAME): $(OBJECTS) $(HEADERS)
# 	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
# 	ar rcs $(NAME) $(OBJECTS) 
# 	@ranlib $(NAME)
# 	@echo "\033[A\033[K\033[A"
# 	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
# 	@echo "                  [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"
 
# $(OBJECT_PATH)%.o: $(SRCS_FILES) $(SRCS_FILES2)
# 	@mkdir $(OBJECT_PATH) 2>/dev/null || echo "" > /dev/null
# 	@$(COMPILE) $(INCLUDES) -c $< -o $@ 

# clean:
# 	@echo "Deleting .o files..."
# 	@rm -f $(OBJECTS)
# 	@rm -rf $(OBJECT_PATH)

# fclean: clean
# 	@echo "Cleaning up..."
# 	@rm -f $(NAME)

# re: fclean all
# 	@echo "Recompiling..."

# .PHONY: clean fclean re all

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
COLOR_PENDING	= \033[0;33m
COLOR_SUCCESS	= \033[0;32m

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "                  [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re