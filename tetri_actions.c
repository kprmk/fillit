/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:01:55 by eshor             #+#    #+#             */
/*   Updated: 2020/01/07 22:31:51 by kprmk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 1 проверка - что там не занято
** 2 проверка - что не вылезаем за пределы карты (то есть не ставим на несуществующий номер)
** 3 проверка - что фигурка не поломалась:
** для этого нужно, чтобы совпадали (относительно) строки, на которых стоит каждый квадратик.
** То есть, curr_pos / map_size  - строка, на которую хотим ставить (с которой начинаем)
** (coord[i] % map_size + curr_pos) / map_size - строка, на которую пытаемся поставить.
** если они не совпадают, значит фигурка разъехалась.
*/
int		can_push_tetri(short *map, int map_size, short *coord, int curr_pos, int r)
{
	int i;
	int str_num;

	i = 0;
	// while (i < 4)
	// {
	// 	if (map[coord[i] + curr_pos] == 1 || coord[i] + curr_pos  > map_size * map_size - 1)
	// 		return (-1);
	// 	if (curr_pos / map_size != ((coord[i] % map_size + curr_pos) / map_size))
	// 		return (-1);
	// 	if ()
	// 	i++;
	// }
	while (i < 4)
	{
		if (map[coord[i] + curr_pos] == 1)
			return (-1);
		i++;
	}
	if (coord[3] + curr_pos  > map_size * map_size - 1)
		return (-1);
	// printf("f %d s %d\n", curr_pos / map_size, (coord[i] % map_size + curr_pos) / map_size);
	if (curr_pos / map_size != ((coord[i] % map_size + curr_pos) / map_size))
		return (-1);
		printf("!!! %d !!! %d \n", (coord[0] + curr_pos) % map_size, r);
	if ((coord[0] + coord[5] + curr_pos) % map_size >= map_size - 1 
		|| (coord[0] + curr_pos) % map_size >= map_size - r)
		return (-1);
	return (0);
}

/*
** не очищаем верхний левый угол и номер, потому что они потом все равно поменяются, когда
** будем ставить эту фигурку в следующий раз
*/
void	clear_tetri(short **map, t_lst **node, int curr_pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*map)[((*node)->coords)[i] + curr_pos] = 0;
		i++;
	}
}
/*
** в карту везде ставим единички, верхний левый угол теперь это текущая позиция, номер фигурки приходит в аргументах
*/
void	push_tetri(short **map, t_lst **node, int curr_pos, int num)
{
	int i;

	i = 0;
	while (i < 4)
	{
		(*map)[((*node)->coords)[i]  + curr_pos] = 1;
		(*node)->upperleft = curr_pos;
		(*node)->index_number = num;
		i++;
	}
}
/*
**Просто ходим по всем клеткам и смотрим, можно ли туда пихнуть фигурку
*/
// int		can_tetri_be_in_map(short *map, int map_size, short *coord)
// {
// 	int		i;
// 	int		*curr_xy;

// 	i = 0;
// 	while (i < map_size * map_size - 1)
// 	{
// 		if (can_push_tetri(map, map_size, coord, i) == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (-1);
// }
