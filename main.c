/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprmk <kprmk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:14:40 by eshor             #+#    #+#             */
/*   Updated: 2020/01/07 22:15:39 by kprmk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(void)
{
	char	file_name[] = "input.txt";
	t_lst	*head;
	int		amount;

	head = NULL;
	amount = 0;
	if (!(amount = validation(file_name, &head)))
		ft_putstr("ERROR\n");
	else
	{
		ft_putstr("SUCCESS\n");
		lst_print(head);
        bruteforce(head, amount);
	}
	return (0);
}