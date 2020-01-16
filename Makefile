# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/11 17:25:06 by eshor             #+#    #+#              #
#    Updated: 2020/01/17 01:33:59 by kprmk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror -g
INC = -I libft/includes
LIB = libft/libft.a
SRCS = fillit.c \
	list.c \
	charmap_actions.c \
	tetri_actions.c \
	tab_actions.c \
	validation.c 

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