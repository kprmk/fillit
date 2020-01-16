/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:16:59 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/17 01:22:43 by kprmk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Solve functions uses backtracking algorithm.
** It places tetriminos on the map one by one starting from the upperleft corner
** and moving from left to right and the from up to down.
** If in the first pass it succeeds in filling the map, that is 
** the decision we're looking for.  If it doesn't, it clears the last placed 
** tetri and tries to place it on the next spot.
** This way it moves from the last tetrimino to the first one.
** If all the options are out, it returns -1 (failure)
*/

int			solve(t_lst *head, short **map, int map_size, t_lst **node, int num)
{
	int r_l_curr[3];

	r_l_curr[0] = (*node)->r;
	r_l_curr[1] = (*node)->l;
	r_l_curr[2] = 0;
	while (r_l_curr[2] < map_size * map_size - 3)
	{
		if (can_push(*map, map_size, (*node)->coords, r_l_curr) == 0)
		{
			push_tetri(map, node, r_l_curr[2], num);
			print_with_letters(head, *node, map_size);
			if ((*node)->next)
			{
				if ((solve(head, map, map_size, &((*node)->next), num + 1)) == 0)
					return (0);
				else
					clear_tetri(map, node, r_l_curr[2]);
			}
			else
				return (0);
		}
		r_l_curr[2]++;
	}
	return (-1);
}

/*
** Initial size of the map where we're placing tetriminos equals
** square root of (number of tetriminos * 4), which is rarely the case.
** Function solve tries to place all tetriminos on this map.
** If it succeeds, bruteforce prints the map with letters.
** If it doesn't, bruteforce deletes the old map and creates a new one.
** The new map's size is one greater.
** That loop repeats until Solve functions returns 0 (success).
*/

void		bruteforce(t_lst *node, int tetri_nbr)
{
	t_lst	*init_head;
	short	*map;
	int		map_size;
	t_lst	*temp;

	init_head = node;
	map_size = ft_sqrt(tetri_nbr * 4);
	temp = node;
	while (temp)
	{
		map_size = check_height(temp->coords, map_size, temp->r, temp->l);
		temp = temp->next;
	}
	map = create_map(map_size);
	lst_foreach(node, (void (*)(void *))move_upleft);
	change_size_for_lst(node, 4, map_size);
	while (solve(init_head, &map, map_size, &node, 0) == -1)
	{
		delete_map(&map);
		map_size++;
		map = create_map(map_size);
		change_size_for_lst(node, map_size - 1, map_size);
	}
	if (print_with_letters(node, NULL, map_size) == -1)
		ft_putstr("error\n");
	delete_map(&map);
}

int		main(int argc, char **argv)
{
	t_lst	*head;
	int		amount;

	head = NULL;
	amount = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((amount = validation(argv[1], &head)) < 1)
		ft_putstr("error\n");
	else
		bruteforce(head, amount);
	lst_del(&head);
	return (0);
}
