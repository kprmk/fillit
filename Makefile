# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshor <eshor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/11 17:25:06 by eshor             #+#    #+#              #
#    Updated: 2020/01/13 13:42:17 by eshor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
COMPILER = gcc
FLAGS = -g -o
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

all: $(NAME)

$(NAME): 
	@$(COMPILER) $(FLAGS) $(NAME) $(SRCS) $(INC) $(LIB)

fclean:
	@rm $(NAME)
	
re: fclean $(NAME)