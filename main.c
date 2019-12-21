/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:14:40 by eshor             #+#    #+#             */
/*   Updated: 2019/12/21 19:53:57 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(void)
{
	t_lst	*head;
	int		amount;
	char	file_name[] = "input.txt";
	int		i;
	int		j;

	head = NULL;
	i = -1;
	j = -1;
	amount = 0;
	if (!check_input_data(file_name, &amount))
		ft_putstr("ERROR\n");
	else
	{
		ft_putstr("SUCCESS\n\n");
		printf("%d\n", amount);
		if (!(second_pass(file_name, &head)))
			printf("Error. Array of coordinates doesn't exist\n");
		else
		{
			lst_print(head);
            // bruteforce(double_array, i);
		}
	}
	return (0);
}

// int main()
// {
// 	t_lst	*head;

// 	head = NULL;
// 	for(int i = 0; i < 11; i++)
// 	{
// 		if (!lst_push_front(&head, lst_new(i)))
// 			return (0);
// 	}
// 	lst_print(head);
// 	ft_putstr("\n\n");
// 	lst_reverse(&head);
// 	lst_print(head);
// 	lst_del(&head);
// 	return (0);
// }