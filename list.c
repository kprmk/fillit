/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:26:29 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/17 01:20:37 by kprmk            ###   ########.fr       */
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

void	lst_reverse(t_lst **head)
{
	t_lst	*prev;
	t_lst	*cur;
	t_lst	*next;

	prev = NULL;
	cur = NULL;
	next = *head;
	while (next)
	{
		cur = next;
		next = next->next;
		cur->next = prev;
		prev = cur;
	}
	*head = cur;
}

/*
** Applies function f to every node of the list.
*/

void	lst_foreach(t_lst *head, void (*f)(void *))
{
	t_lst	*current;

	current = head;
	while (current)
	{
		(*f)(&(current->coords));
		current = current->next;
	}
}

int		amount_of_items(t_lst *head, t_lst *cur)
{
	int counter;

	counter = 0;
	while (head != cur)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

