/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:53:40 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/17 01:21:24 by kprmk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	check_4(short *ar)
{
	int	i;

	i = 0;
	if (ar[i] == ar[i + 2] && ar[i + 4] == ar[i + 6])
		return (1);
	while (i < 6)
	{
		if (ar[i + 2] - ar[i] != 1)
			return (0);
		i += 2;
	}
	return (1);
}

char	check_adjacent(short *ar, int sum)
{
	if (sum == 3)
		return (1);
	else if (sum == 4)
		return (check_4(ar));
	else
		return (0);
}

char	check_area(short *ar, int i, int j)
{
	int		sum;

	i = 2;
	sum = 0;
	while (i < 8)
	{
		if (ar[(int)i] == -1)
			return (0);
		j = 0;
		while (j < i)
		{
			if (ar[(int)i] - ar[(int)j] == 1
				&& ar[(int)i + 1] == ar[(int)j + 1])
				sum += 1;
			if (ft_mod(ar[(int)i + 1] - ar[(int)j + 1]) == 1
				&& ar[(int)i] == ar[(int)j])
				sum += 1;
			j += 2;
		}
		i += 2;
	}
	return (check_adjacent(ar, sum));
}

void	deep_and_hor(t_lst **head, short *mas)
{
	short	min;
	short	max;
	char	i;

	i = 3;
	min = mas[1];
	max = mas[1];
	while (i <= 7)
	{
		if (mas[(int)i] < min)
			min = mas[(int)i];
		if (mas[(int)i] > max)
			max = mas[(int)i];
		i += 2;
	}
	(*head)->r = max - mas[1];
	(*head)->l = mas[1] - min;
}

char	check_of_ending_block(t_lst **head, short **mas, int *i, char *ar)
{
	char x;
	char y;

	x = 0;
	y = 0;
	if (++(*i) == 4)
	{
		if (!check_area((*head)->coords, (int)x, (int)y))
			return (0);
		ar[0] = 0;
		ar[1]++;
		deep_and_hor(head, *mas);
		if (!lst_push_front(head, lst_new(head, ar[1])))
		{
			return (0);
		}
		*i = -1;
		endblock_loop(mas);
	}
	return (1);
}

void	endblock_loop(short **mas)
{
	char x;
	char y;
	char f;

	f = 0;
	x = 1;
	y = -1;
	while (++y < 7)
	{
		if (y < 4)
		{
			if (*(*mas + x) + 4 * f <= *(*mas + y - 1) && y)
				f++;
			*(*mas + y) = *(*mas + x) + 4 * f;
		}
		else
			*(*mas + y) = 0;
		x += 2;
	}
}

int		check_input_with_lst(t_lst **head, char *str, int *i, char *ar)
{
	int x;

	x = -1;
	if ((*str && (ft_strlen(str) != 4 || (*i) == -1)))
		return (0);
	if (!(*i) && !(ar[1]))
		if (!lst_push_front(head, lst_new(head, ar[1])))
			return (0);
	while (str[++x])
	{
		if (str[x] == '#' && ar[0] < 8)
		{
			(*head)->coords[(int)ar[0]++] = *i;
			(*head)->coords[(int)ar[0]++] = x;
		}
		else if (str[x] != '.' || (ar[0] > 7 && str[x] == '#'))
			return (0);
	}
	if (!check_of_ending_block(head, &((*head)->coords), i, ar))
		return (0);
	return (1);
}

/*
** Checks one tetrimino from input.	
** After that deletes allocated array.
*/

int		check_tetri(char ***tetri_ar, int *i, t_lst **head, char *ar)
{
	int j;
	int res;

	if (ar_length(*tetri_ar) != 4 && (ar_length(*tetri_ar) != 5 && *i == 0))
		return (0);
	j = 0;
	res = 1;
	while (j < 4)
	{
		if (check_input_with_lst(head, (*tetri_ar)[j], i, ar) < 1)
			res = 0;
		j++;
	}
	delete_charmap(tetri_ar, 4);
	return (res);
}

int		validation(char *file_name, t_lst **head)
{
	char	str[21];
	char	**tetri_ar;
	int		fd;
	int		i;
	char	ar[4];

	ar[0] = 0;
	ar[1] = 0;
	ar[2] = 0;
	ar[3] = 0;
	if ((fd = open((const char *)file_name, O_RDONLY)) == -1)
		return (-1);
	while ((ar[3] = read(fd, str, 21)))
	{
		i = 0;
		if (((ar[2] = ar[3]) != 21) && ar[3] != 20)
			return (0);
		tetri_ar = ft_strsplit(str, '\n');
		if (check_tetri(&tetri_ar, &i, head, ar) == 0)
			return (0);
	}
	if (ar[2] != 20 || i != -1 || lst_len(*head) > 26)
		return (-1);
	lst_rev(head, fd);
	return (ar[1]);
}
