# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:21:58 by parkharo          #+#    #+#              #
#    Updated: 2023/02/18 14:50:27 by parkharo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a

SRC_PATH 		=	./srcs/
SRC2_PATH		=	./srcs/ft_printf/
SRCS_FILES		=	$(wildcard $(SRC_PATH)*.c)
SRCS2_FILES		=	$(wildcard $(SRC2_PATH)*.c)

OBJECT_PATH		=	./objs/
OBJECT_FILES	=	$(SRCS_FILES:%.c=%.o)
OBJECT2_FILES	=   $(SRCS2_FILES:%.c=%.o)
OBJECTS			=	$(addprefix $(OBJECT_PATH), $(OBJECT_FILES))
OBJECTS			+=  $(addprefix $(OBJECT_PATH), $(OBJECT2_FILES))
OBJ 			:=  $(SRCS_FILES:$(SRCS_PATH)%.c=$(OBJECT_PATH)%.o)
OBJ 			+=  $(SRCS_FILES2:$(SRCS2_PATH)%.c=$(OBJECT_PATH)%.o)

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

print: 
	@echo $(OBJ)

print2: 
	@echo $(SRCS_FILES)
	@echo "ASDASDAS"
	@echo $(SRCS2_FILES)

$(NAME): $(OBJECTS) $(HEADERS)
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	ar rcs $(NAME) $(OBJECTS) 
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "                  [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"
 
$(OBJECT_PATH)%.o: $(SRCS)
	@mkdir $(OBJECT_PATH) 2>/dev/null || echo "" > /dev/null
	@$(COMPILE) $(INCLUDES) -c $< -o $@ 

clean:
	@echo "Deleting .o files..."
	@rm -f $(OBJECTS)
	@rm -rf $(OBJECT_PATH)

fclean: clean
	@echo "Cleaning up..."
	@rm -f $(NAME)

re: fclean all
	@echo "Recompiling..."

.PHONY: clean fclean re all
