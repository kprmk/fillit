/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:44 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/16 20:39:06 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

//
#include <stdio.h>
//

void	print_table(int **table);
int		**init_table(int **table);
int		check_spot(int **table, int i, int j);
int		check_square_tetramino(int **table);
int		check_tetraminos(int ***table);
int		check_input_with_table(int ***table, char *str, int *i, int *size);
int		check_input_data(char *file_name, int *size);
void	fill_double_array(char ***p_double_array, int *ar, char *str, int *i);
char	**second_pass(char *file_name, int amount);
int		ft_sqrt(int nbr);
void	find_min_coords(char *line, int *min_x, int *min_y);
int		print_map(char **map, int size);
char	**create_map(int size);
void	delete_map(char ***map, int map_size);
void	move_upleft(char ***tab, int size);
int		can_push_tetri(char ***map, int map_size, char *coord, int *curr_xy);
void	clear_tetri(char ***map, char *coord, int curr_x, int curr_y);
void	push_tetri(char ***map, char *coord, int curr_x, int curr_y);
int		can_tetri_be_in_map(char **map, int map_size, char *coord);
int		*find_next_upperleft(char **map, int map_size, int *curr_xy);
int		solve(char ***map, int map_size, char **tab, int num, int total);
void	bruteforce(char **tab, int tetri_nbr);



HOOY


#endif
