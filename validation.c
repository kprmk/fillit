/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:53:40 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/16 15:09:26 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
**	Each character must be either a block character(’#’)
**	or an empty character (’.’)
*/

int		check_tetri(char ***tetri_ar, int *i, t_lst **head, char *ar)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (check_input_with_lst(head, (*tetri_ar)[j], i, ar) < 1)
			return (0);
		j++;
	}
	delete_charmap(tetri_ar, 4);
	return (1);
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
