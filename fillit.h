/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:44 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/23 17:07:10 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

//
#include <stdio.h>
//

typedef	struct	s_lst
{
	int 			index_number:7;
	char            *coords;
	struct s_lst	*next;
}				t_lst;

t_lst	*lst_new(int counter);
int 	lst_push_front(t_lst **head, t_lst *new);
void	lst_del(t_lst **head);
void    lst_print(t_lst *head);
void    lst_reverse(t_lst **head);
void    lst_foreach(t_lst *head, void (*f)(void *));

int		check_input_with_lst(t_lst **head, char *str, int *i, char *ar);
int		validation(char *file_name, t_lst **head);
char	check_area(char *ar);

int		ft_sqrt(int nbr);
void	find_min_coords(char *line, int *min_x, int *min_y);
int		print_map(short *map, int size);
short	*create_map(int size);
void	delete_map(short **map);
void	move_upleft(char **coords);
int		can_push_tetri(short *map, int map_size, char *coord, int curr_pos);
void	clear_tetri(short **map, char *coord, int curr_pos);
void	push_tetri(short **map, char *coord, int curr_pos);
int		can_tetri_be_in_map(short *map, int map_size, char *coord);
int		find_next_upperleft(int map_size, int curr_pos);
int		solve(short **map, int map_size, t_lst *node);
void	bruteforce(t_lst *node,  int tetri_nbr);

void	change_map_size_for_coords(char **coords, int src_size, int dest_size);

#endif
