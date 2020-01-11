/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:53:41 by eshor             #+#    #+#             */
/*   Updated: 2020/01/11 17:26:31 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_upleft(short **c)
{
	int empty_rows;
	int empty_columns;
	int i;

	i = 1;
	empty_rows = 0;
	empty_columns = 0;
	while (i < 4)
	{
		if ((*c)[0] % 4 >= i && (*c)[1] % 4 >= i && (*c)[2] % 4 >= i && (*c)[3] % 4 >= i)
			empty_columns++;
		i++;
	}
	i = 4;
	while (i < 16)
	{
		if ((*c)[0] / i > 0 && (*c)[1] / i > 0 && (*c)[2] / i > 0 && (*c)[3] / i > 0)
			empty_rows++;
		i += 4;
	}
	i = 0;
	while (i < 4)
	{
		(*c)[i] = (*c)[i] - empty_rows * 4 - empty_columns;
		i++;
	}
}

void	change_map_size(short **c, int src_size, int dest_size)
{
	int i;
	int j;
	int diff;

	i = 0;
	j = 0;
	diff = dest_size - src_size;
	while (i < 4)
	{
		(*c)[i] = (*c)[i] / src_size * diff + (*c)[i];
		i++;
	}
}
