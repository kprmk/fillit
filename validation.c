/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:53:40 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/28 17:56:10 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	cpy_even(char **src, char **dst)
{
	char 	i;
	char	j;

	i = 1;
	j = 0;
	while (i < 8)
	{
		*dst[j++] = *src[i];
		i += 2;
	}
	return (1);
}

char	check_of_ending_block(t_lst **head, char **ar_coords, char **ar)
{
	if (++(*ar[2]) == 4)
	{
		if (check_area(*ar_coords))
			cpy_even(ar_coords, &((*head)->coords));
		else	
			return (0);
		// if (!check_area((*head)->coords))
		// 	return (0);
		*ar[0] = 0;
		*ar[1] += 1;
		if (!lst_push_front(head, lst_new(*ar[1])))
			return (0);
		*ar[2] = -1;
	}
	return (1);
}

int		check_input_with_lst(t_lst **head, char *str, char **ar)
{
	char	x;
	char	**array_coords;

	x = -1;
	if (*str && (ft_strlen(str) != 4 || (*(*ar + 2) == -1)))
		return (0);
	if (!(*(*ar + 2)) && !(*(*ar + 1)))
		if (!lst_push_front(head, lst_new(*(*ar + 1))))
			return (0);
	while (str[++x])
	{
		if (str[x] == '#' && **ar < 8)
		{
			// (*head)->coords[ar[0]++] = *i;
			// (*head)->coords[ar[0]++] = x;
			*array_coords[*ar[0]++] = *ar[2];
			*array_coords[*ar[0]++] = x;
		}
		else if (str[x] != '.' || (*ar[0] > 7 && str[x] == '#'))
			return (0);
	}
	if (!check_of_ending_block(head, array_coords, ar))
		return (0);
	free(*array_coords);
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
	char	**ar;

	i = -1;
	ar = (char **)malloc(sizeof(char*));
	*ar = (char *)malloc(sizeof(char) * 4);
	while (++i < 3)
		*(*ar + i) = 0;
	if ((fd = open((const char *)file_name, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &str))
		if (!check_input_with_lst(head, str, ar))
			return (0);
	temp = *head;
	*head = (*head)->next;
	free(temp->coords);
	free(temp);
	lst_reverse(head);
	close(fd);
	return (*ar[1]);
}
