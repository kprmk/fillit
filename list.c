/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:26:29 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/13 19:52:05 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*lst_new(int counter)
{
	t_lst	*res;
	int		i;

	i = -1;
	if (!(res = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	res->index_number = counter;
	if (!(res->coords = (short *)malloc(sizeof(short) * 8)))
		return (NULL);
	while (++i < 8)
		res->coords[i] = -1;
	res->next = NULL;
	return (res);
}

int		lst_push_front(t_lst **head, t_lst *new)
{
	if (!new)
		return (0);
	if (*head)
		new->next = *head;
	*head = new;
	return (1);
}

void	lst_rec(t_lst *current)
{
	if (current)
	{
		lst_rec(current->next);
		free(current->coords);
		free(current);
	}
}

void	lst_del(t_lst **head)
{
	if (head && *head)
	{
		lst_rec(*head);
		*head = NULL;
	}
}
