/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charmap_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:26:11 by eshor             #+#    #+#             */
/*   Updated: 2020/01/17 01:23:22 by kprmk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Deletes any double pointer to char.
*/

void	delete_charmap(char ***map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

/*
** Prints any double pointer to char.
*/

void	print_charmap(char **map, int map_size)
{
	int x;
	int y;

	y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

/*
** Creates double pointer to char - two-dimensional square array of char.
** This is the square where we're trying to place tetriminos.
*/

char	**create_charmap(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	if (!(map = ((char**)malloc(sizeof(char*) * size * size))))
		return (NULL);
	while (i < size)
	{
		map[i] = (char*)malloc(sizeof(char) * size);
		if (!map[i])
		{
			delete_charmap(&map, i);
			return (NULL);
		}
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

/*
** Prints map with tetriminos on it.
** Each tetrimino is represented by 4 letters, one letter for each tetrimino.
** List structure stores the order of placing tetriminos - index_number.
** That index plus 'A' gives us the necessary letter.
** usleep(num) -> the function suspends execution of the calling thread for 
** (at least) num MICROSEC!
*/

int		print_with_letters(t_lst *head, t_lst *cur, int size)
{
	int		amount;
	int		counter;
	int		x;
	char	**map;

	usleep(200000);
	ft_putstr("\e[1;1H\e[2J");
	amount = amount_of_items(head, cur);
	counter = 0;
	map = create_charmap(size);
	while (head && counter++ <= amount)
	{
		x = 0;
		while (x < 4)
		{
			map[((head->coords)[x] + head->upperleft) / size][((head->
			coords)[x] + head->upperleft) % size] = 'A' + head->index_number;
			x++;
		}
		head = head->next;
	}
	print_charmap(map, size);
	delete_charmap(&map, size);
	return (0);
}

char	ft_mod(int a)
{
	return (a < 0 ? -a : a);
}

int		ft_sqrt(int nbr)
{
	int result;

	result = 1;
	while (result * result < nbr)
		result++;
	return (result);
}

/*
** Ends validation:
** reverses list, closes file descriptor.
*/

void	lst_rev(t_lst **head, int fd)
{
	t_lst *temp;

	temp = *head;
	*head = (*head)->next;
	free(temp->coords);
	free(temp);
	lst_reverse(head);
	close(fd);
}

int		ar_length(char **tetri)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		i++;
	}
	return (i);
}
