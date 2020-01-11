/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:14:40 by eshor             #+#    #+#             */
/*   Updated: 2020/01/11 17:26:03 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_lst	*head;
	int		amount;
//	char *line;

	head = NULL;
	amount = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
/*	amount = open(argv[1], O_RDONLY);
	printf("%d\n", amount);
	get_next_line(amount, &line);
	printf("%s\n", line);
	if (ft_strcmp(line, "") == 0)
		printf("%s\n", "NULL");*/
	if ((amount = validation(argv[1], &head)) < 1)
		ft_putstr("error\n");
	else
	{
		lst_print(head);
		bruteforce(head, amount);
	}
	return (0);
}
