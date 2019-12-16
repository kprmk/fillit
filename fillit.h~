/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:51:44 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/07 16:09:21 by mbrogg           ###   ########.fr       */
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

#endif
