/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:16:59 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/20 19:43:57 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve(char ***map, int map_size, char **tab, int num, int total)
{
	int *curr_xy;

	curr_xy = (int*)malloc(sizeof(int) * 2);
	curr_xy[0] = 0;
	curr_xy[1] = 0;
	while (curr_xy != NULL)
	{
		if (can_push_tetri(map, map_size, tab[num], curr_xy) == 0)
		{
			push_tetri(map, tab[num], curr_xy, num);
			// print_map(*map, map_size);
			if (num + 1 < total)
			{
				if ((can_tetri_be_in_map(*map, map_size, tab[num + 1])) == 0)
				{
					if ((solve(map, map_size, tab, num + 1, total)) == 0)
						return (0);
					else
						clear_tetri(map, tab[num], curr_xy[0], curr_xy[1]);
					
				}
				else
					clear_tetri(map, tab[num], curr_xy[0], curr_xy[1]);
			}
			else
				return (0);
		}
		curr_xy = find_next_upperleft(map_size, curr_xy);
	}
	return (-1);
}

void		bruteforce(char **tab, int tetri_nbr)
{
	char	**map;
	int		j;
	int		map_size;
	
	move_upleft(&tab, tetri_nbr);
	map_size = ft_sqrt(tetri_nbr * 4);
	map = create_map(map_size);
	print_map(map, map_size);
	j = -1;
	while (j == -1)
	{
		j = solve(&map, map_size, tab, 0, tetri_nbr);
		if (j == -1)
		{
			delete_map(&map, map_size);
			map_size++;
			map = create_map(map_size);
			printf("%s\n", "map too small");
		}
		else
			print_map(map, map_size);
	}
}
