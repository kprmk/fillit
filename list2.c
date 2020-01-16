/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:41:46 by eshor             #+#    #+#             */
/*   Updated: 2020/01/16 17:38:00 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
