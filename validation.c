/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:53:40 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/11 17:18:07 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (mas[i] < min)
			min = mas[i];
		if (mas[i] > max)
			max = mas[i];
		i += 2;
	}
	(*head)->deep = mas[6] - mas[0];
	(*head)->r = max - mas[1];
	(*head)->l = mas[1] - min;
}

char	check_of_ending_block(t_lst **head, short **mas, int *i, char *ar)
{
	char	x;
	char	y;
	char	f;

	f = 0;
	if (++(*i) == 4)
	{
		if (!check_area((*head)->coords, x, y))
			return (0);
		ar[0] = 0;
		ar[1]++;
		deep_and_hor(head, *mas);
		// (*head)->coords[5] = (*head)->r;
		// printf("%d %d \n",(*mas)[4] ,(*head)->r);
		if (!lst_push_front(head, lst_new(ar[1])))
			return (0);
		*i = -1;
		x = 1;
		y = 0;
		while (y < 8)
		{
			if (y < 4)
			{
				if (*(*mas + x) + 4 * f <= *(*mas + y - 1) && y)
					f++;
				*(*mas + y) = *(*mas + x) + 4 * f;
				// *(*mas + y) = *(*mas + x);
			}
			else
				*(*mas + y) = 0;
			y++;
			x += 2;
		}
	}
	return (1);
}

int		check_input_with_lst(t_lst **head, char *str, int *i, char *ar)
{
	int x;

	x = -1;
	if ((*str && (ft_strlen(str) != 4 || (*i) == -1)))
		return (0);
	if (!(*i) && !(ar[1]))
		if (!lst_push_front(head, lst_new(ar[1])))
			return (0);
	while (str[++x])
	{
		if (str[x] == '#' && ar[0] < 8)
		{
			(*head)->coords[ar[0]++] = *i;
			(*head)->coords[ar[0]++] = x;
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

int		validation(char *file_name, t_lst **head)
{
	char	*str;
	int		fd;
	int		i;
	t_lst	*temp;
	char	ar[3];

	ar[0] = 0;
	ar[1] = 0;
	i = 0;
	ar[2] = 0;
	if ((fd = open((const char *)file_name, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &str))
	{
		ar[2] = 1;
		if (check_input_with_lst(head, str, &i, ar) < 1)
			return (0);
	}
	if (ar[2] == 0)
		return (-1);
	temp = *head;
	*head = (*head)->next;
	free(temp->coords);
	free(temp);
	lst_reverse(head);
	close(fd);
	return (ar[1]);
}
