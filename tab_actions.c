/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:53:41 by eshor             #+#    #+#             */
/*   Updated: 2019/12/12 16:54:25 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_upleft(char ***tab, int size)
{
	int i;
	int j;
	int min_x;
	int min_y;

	i = 0;
	j = 0;
	min_x = 3;
	min_y = 3;
	while (i < size)
	{
		find_min_coords((*tab)[i], &min_x, &min_y);
		j = 0;
		while (j < 8)
		{
			(*tab)[i][j] -= min_x;
			(*tab)[i][j + 1] -= min_y;
			j += 2;
		}
		i++;
	}
}
