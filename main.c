/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:14:40 by eshor             #+#    #+#             */
/*   Updated: 2020/01/14 16:23:17 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int		main(int argc, char **argv)
{
	t_lst	*head;
	int		amount;

	head = NULL;
	amount = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((amount = validation(argv[1], &head)) < 1)
		ft_putstr("validaerror\n");
	else
	{
		bruteforce(head, amount);
	}
	lst_del(&head);
	return (0);
}
