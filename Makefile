# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/11 17:25:06 by eshor             #+#    #+#              #
#    Updated: 2020/01/16 19:27:33 by mbrogg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
INC = -I libft/includes
LIB = libft/libft.a
SRCS = fillit.c \
	aux_funcs.c \
	list.c \
	list2.c \
	main.c \
	map_actions.c \
	charmap_actions.c \
	tetri_actions.c \
	tab_actions.c \
	validation.c \
	validation_checks.c

OBJ		= $(SRC:.c=.o)

.PHONY: all clean fclean re

%.o: %.c
	@$(COMPILER) $(FLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@make -C libft/
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ) $(SRCS) $(INC) $(LIB)
	
clean:
	@make -C libft clean
	
fclean:
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

all: $(NAME)