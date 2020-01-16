/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:53:41 by eshor             #+#    #+#             */
/*   Updated: 2020/01/16 17:31:58 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** In the input file tetriminos can be anywhere on the 4x4 square.
** For convenience we move them all in the upperleft corner,
** because we start filling the map from that spot.
*/
void	move_upleft(short **c)
{
	int empty_rows;
	int empty_columns;
	int i;

	i = 0;
	empty_rows = 0;
	empty_columns = 0;
	while (i++ < 4)
	{
		if ((*c)[0] % 4 >= i && (*c)[1] % 4 >= i &&
		(*c)[2] % 4 >= i && (*c)[3] % 4 >= i)
			empty_columns++;
	}
	i = 4;
	while (i < 16)
	{
		if ((*c)[0] / i > 0 && (*c)[1] / i > 0
		&& (*c)[2] / i > 0 && (*c)[3] / i > 0)
			empty_rows++;
		i += 4;
	}
	i = -1;
	while (++i < 4)
		(*c)[i] = (*c)[i] - empty_rows * 4 - empty_columns;
}

/*
** Changes coordinates of one tetrimino
** according to the size of the map we're placing them on.
*/
void	change_map_size(short **c, int src_size, int dest_size)
{
	int i;
	int diff;

	i = 0;
	diff = dest_size - src_size;
	while (i < 4)
	{
		(*c)[i] = (*c)[i] / src_size * diff + (*c)[i];
		i++;
	}
}

/*
** Changes coordinates of all tetriminos according to the size of the map.
*/
void	change_size_for_lst(t_lst *node, int start_size, int dest_size)
{
	t_lst	*temp;

	temp = node;
	while (temp)
	{
		change_map_size(&(temp->coords), start_size, dest_size);
		temp = temp->next;
	}
}
