# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshor <eshor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/11 17:25:06 by eshor             #+#    #+#              #
#    Updated: 2020/01/13 17:08:19 by eshor            ###   ########.fr        #
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
all: $(NAME)

%.o:%.c
	$(COMPILER) $(FLAGS) $(INC) -o $@ -c $<

$(NAME): lib $(OBJ)
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ) $(SRCS) $(INC) $(LIB)

lib:
	make -C libft
	
clean:
	make clean -C libft
	
fclean:
	make fclean -C libft
	
re: fclean all