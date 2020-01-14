/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:26:29 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/14 16:21:14 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*lst_new(t_lst **head, int counter)
{
	t_lst	*res;
	int		i;

	i = -1;
	if (!(res = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	res->index_number = counter;
	if (!(res->coords = (short *)malloc(sizeof(short) * 8)))
	{
		lst_del(head);
		return (NULL);
	}
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

void	lst_rec(t_lst **current)
{
	if (*current)
	{
		lst_rec(&(*current)->next);
		free((*current)->coords);
		free(*current);
	}
}

void	lst_del(t_lst **head)
{
	if (head && *head)
	{
		lst_rec(head);
		*head = NULL;
	}
}

int		lst_len(t_lst *head)
{
	int counter;

	counter = 0;
	while (head->next)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}
