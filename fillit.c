/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:16:59 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/08 13:14:02 by kprmk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve(short **map, int map_size, t_lst **node, int num, t_lst *print)
{
	int curr_pos;
	int r_l[2];

	r_l[0] = (*node)->r;
	r_l[1] = (*node)->l;
	curr_pos = 0;
	while (curr_pos < map_size * map_size - 3)
	{
		if (can_push_tetri(*map, map_size, (*node)->coords, curr_pos, r_l) == 0)
		{
			push_tetri(map, node, curr_pos, num);
			// print_with_letters(print, *node, map_size);
			if ((*node)->next)
			{
				// if ((can_tetri_be_in_map(*map, map_size, (*node)->next->coords)) == 0)
				// {
				// 	if ((solve(map, map_size, &((*node)->next), num + 1)) == 0)
				// 		return (0);
				// 	else
				// 		clear_tetri(map, node, curr_pos);	
				// }
				// else
				// 	clear_tetri(map, node, curr_pos);

				if ((solve(map, map_size, &((*node)->next), num + 1, print)) == 0)
					return (0);
				else
				{
					clear_tetri(map, node, curr_pos);		
					// print_with_letters(print, *node, map_size);
				}
			}
			else
				return (0);
		}
		curr_pos++;
	}
	return (-1);
}

void		bruteforce(t_lst *node,  int tetri_nbr)
{
	//
	t_lst	*main_print = node;
	//
	short	*map;
	int		j;
	int		map_size;
	t_lst	*temp;
	
	map_size = ft_sqrt(tetri_nbr * 4);
	printf("initial_map_size -> %d\n", map_size);
	map = create_map(map_size);
	lst_foreach(node, (void (*)(void *))move_upleft);
	temp = node;
	while (temp)
	{
		change_map_size_for_coords(&(temp->coords), 4, map_size);
		temp = temp->next;
	}	
	j = -1;
	while (j == -1)
	{
		j = solve(&map, map_size, &node, 0, main_print);
		if (j == -1)
		{
			delete_map(&map);
			map_size++;
			printf("c_map_size -> %d\n", map_size);
			map = create_map(map_size);
			temp = node;
			while (temp)
			{
				change_map_size_for_coords(&(temp->coords), map_size - 1, map_size);
				temp = temp->next;
			}
		}
//		else
//			print_map(map, map_size);
	}
//	lst_print(node);
	if (print_with_letters(node, NULL, map_size) == -1)
		ft_putstr("ERROR\n");
}
