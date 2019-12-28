/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:44 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/28 17:46:52 by mbrogg           ###   ########.fr       */
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

int		check_input_with_lst(t_lst **head, char *str, char **ar);
int		validation(char *file_name, t_lst **head);
char	check_area(char *ar);

int		ft_sqrt(int nbr);
void	find_min_coords(char *line, int *min_x, int *min_y);
int		print_map(char **map, int size);
char	**create_map(int size);
void	delete_map(char ***map, int map_size);
void	move_upleft(char ***tab, int size);
int		can_push_tetri(char ***map, int map_size, char *coord, int *curr_xy);
void	clear_tetri(char ***map, char *coord, int curr_x, int curr_y);
void	push_tetri(char ***map, char *coord, int *curr, int num);
int		can_tetri_be_in_map(char **map, int map_size, char *coord);
int		*find_next_upperleft(int map_size, int *curr_xy);
int		solve(char ***map, int map_size, char **tab, int num, int total);
void	bruteforce(char **tab, int tetri_nbr);

#endif
