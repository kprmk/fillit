/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:01:55 by eshor             #+#    #+#             */
/*   Updated: 2020/01/10 17:04:59 by eshor            ###   ########.fr       */
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
int		can_push_tetri(short *map, int map_size, short *coord, int curr_pos, int *r_l)
{
	int i;

	i = 0;	
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
		// printf("!!! %d !!! %d !!!\n", (coord[0] + curr_pos) % map_size, map_size - r_l[0]);
	if ((coord[0] + curr_pos) % map_size >= map_size - r_l[0])
	{
		// printf("\nTHE FIRST\n");
		return (-1);
	}
	// printf("### %d ### %d ###\n", (coord[0] + curr_pos) - r_l[1] % map_size, map_size - r_l[0]);
	if (((coord[0] + curr_pos - r_l[1]) % map_size > map_size - (r_l[0] + r_l[1] + 1)))
	{
		// printf("\nTHE SECOND\n");
		return (-1);
	}
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

int		check_height(short *coords, int map_size)
{
	int i;
	int length;
	int min;
	int max;

	if (map_size > 3)
		return (map_size);
	i = 0;
	min = 15;
	max = 0;
	while (i < 4)
	{
		if (coords[i] > max)
			max = coords[i];
		if (coords[i] < min)
			min = coords[i];
		i++;
	}
	length = max % 4 - min % 4 + 1;
	if (length > map_size)
		return (length);
	else
		return (map_size);
}