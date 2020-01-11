# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshor <eshor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/11 17:25:06 by eshor             #+#    #+#              #
#    Updated: 2020/01/11 17:46:38 by eshor            ###   ########.fr        #
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
	main.c \
	map_actions.c \
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