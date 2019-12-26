/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:53:41 by eshor             #+#    #+#             */
/*   Updated: 2019/12/23 17:09:46 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
void	move_upleft(char **coords)
{
	int empty_rows;
	int empty_columns;
	int i;
	int j;

	i = 1;
	empty_rows = 0;
	empty_columns = 0;
	while (i < 4)
	{
		if ((*coords)[0] % 4 >= i && (*coords)[1] % 4 >= i && (*coords)[2] % 4 >= i && (*coords)[3] % 4 >= i)
			empty_columns++;
		i++;
	}
	i = 4;
	while (i < 16)
	{
		if ((*coords)[0] / i > 0 && (*coords)[1] / i > 0 && (*coords)[2] / i > 0 && (*coords)[3] / i > 0)
			empty_rows++;
		i += 4;
	}
	i = 0;
	while (i < 4)
	{
		(*coords)[i] = (*coords)[i] - empty_rows * 4 - empty_columns;
		i++;
	}
}

void	change_map_size_for_coords(char **coords, int src_size, int dest_size)
{
	int i;
	int j;
	int diff;

	i = 0;
	j = 0;
	diff = dest_size - src_size;
	while (i < 4)
	{
		(*coords)[i] = (*coords)[i] / src_size * diff + (*coords)[i];
		i++;
	}
}
