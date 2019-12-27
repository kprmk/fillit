/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:14:40 by eshor             #+#    #+#             */
/*   Updated: 2019/12/23 17:10:06 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
эта херня просто потому что я не знаю как ты записываешь координаты в листы
*/
void	write_coords(t_lst	*head, char *coords)
{
	int i;

	i = 0;
	while (i < 4)
	{
		head->coords[i] = coords[i] - 48;
		i++;
	}
} 

int		main(void)
{
	char	file_name[] = "input.txt";
	t_lst	*head;
	t_lst	*temp;
	int		amount;

	

	head = NULL;
	amount = 2;
	head = lst_new(0);
	
	head->coords[0] = 1;
	head->coords[1] = 5;
	head->coords[2] = 9;
	head->coords[3] = 13;
//	write_coords(head, "3700");
	head->next = lst_new(1);
	write_coords(head->next, "0145");
	lst_print(head);
//	change_map_size_for_coords(&(head->coords), 4, 3);
//	lst_print(head);
	move_upleft(&(head->coords));
	lst_print(head);
	bruteforce(head, amount);
/*
	if (!(amount = validation(file_name, &head)))
		ft_putstr("ERROR\n");
	else
	{
		ft_putstr("SUCCESS\n");
//		lst_print(head);
		lst_foreach(head, (void (*))move_upleft);
		lst_print(head);
//         bruteforce(head, amount);
	}*/
	return (0);
}