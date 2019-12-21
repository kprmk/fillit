/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:53:40 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/21 23:35:20 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	check_of_ending_block(t_lst **head, int *i, char *ar)
{
	if (++(*i) == 4)
	{
		if (!check_area((*head)->coords))
			return (0);
		ar[0] = 0;
		ar[1]++;
		if (!lst_push_front(head, lst_new(ar[1])))
			return (0);
		*i = -1;
	}
	return (1);
}

int		check_input_with_lst(t_lst **head, char *str, int *i, char *ar)
{
	int x;

	x = -1;
	if (*str && (ft_strlen(str) != 4 || (*i) == -1))
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
	if (!check_of_ending_block(head, i, ar))
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
	char	ar[2];

	ar[0] = 0;
	ar[1] = 0;
	i = 0;
	if ((fd = open((const char *)file_name, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &str))
		if (!check_input_with_lst(head, str, &i, ar))
			return (0);
	temp = *head;
	*head = (*head)->next;
	free(temp->coords);
	free(temp);
	lst_reverse(head);
	close(fd);
	return (ar[1]);
}
