/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:16:59 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/23 16:18:03 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
int			solve(char **map, int map_size, t_list *node)
{
	int curr_pos;

	curr_pos = 0;
	while (curr_xy != -1)
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
		curr_pos = find_next_upperleft(map_size, curr_pos);
	}
	return (-1);
}
*/
void		bruteforce(t_lst *node,  int tetri_nbr)
{
	short	*map;
	int		j;
	int		map_size;
	
	map_size = ft_sqrt(tetri_nbr * 4);
	map = create_map(map_size);
	print_map(map, map_size);
	change_map_size_for_coords(&(node->coords), 4, map_size);
	change_map_size_for_coords(&(node->next->coords), 4, map_size);
	lst_print(node);
	push_tetri(&map, node->next->coords, 4);
	print_map(map, map_size);
	clear_tetri(&map, node->next->coords, 4);
	print_map(map, map_size);
//	print_map(map, map_size);
//	solve(&map, map_size, node);
	/*
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
	}*/
}
