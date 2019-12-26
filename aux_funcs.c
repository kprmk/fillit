/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:52:44 by eshor             #+#    #+#             */
/*   Updated: 2019/12/23 12:59:26 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nbr)
{
	int result;

	result = 1;
	while (result * result < nbr)
		result++;
	return (result);
}

void	find_min_coords(char *line, int *min_x, int *min_y)
{
	int j;

	j = 0;
	*min_x = 3;
	*min_y = 3;
	while (j < 8)
	{
		if (line[j] < *min_x)
			*min_x = line[j];
		if (line[j + 1] < *min_y)
			*min_y = line[j + 1];
		j += 2;
	}
}
