# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshor <eshor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/11 17:25:06 by eshor             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2020/01/14 15:28:59 by eshor            ###   ########.fr        #
=======
#    Updated: 2020/01/14 16:07:34 by mbrogg           ###   ########.fr        #
>>>>>>> d56d2534f2843a331d07e9cc14e756b89371b9b8
#                                                                              #
# **************************************************************************** #

NAME = fillit
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror -g
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

%.o:%.c
	$(COMPILER) $(FLAGS) $(INC) -o $@ -c $<

$(NAME): lib $(OBJ)
	@$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ) $(SRCS) $(INC) $(LIB)

lib:
	cd libft && make
	
clean:
	cd libft && make clean
	
fclean:
	cd libft && make fclean
	rm $(NAME)

re: fclean all

all: $(NAME)