/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:14:40 by eshor             #+#    #+#             */
/*   Updated: 2019/12/16 20:45:58 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(void)
{
	int		amount;
	char	file_name[] = "input.txt";
	char	**double_array;
	int		i;
	int		j;


	i = -1;
	j = -1;
	amount = 0;
	if (!check_input_data(file_name, &amount))
		ft_putstr("ERROR\n");
	else
	{
		ft_putstr("SUCCESS\n\n");
		if (!(double_array = second_pass(file_name, amount)))
			printf("Error. Array of coordinates doesn't exist\n");
		else
		{
			while (double_array[++i])
			{
				j = -1;
				while (++j < 8)
					printf("%d ", double_array[i][j]);
				printf("\n");
			}
            bruteforce(double_array, i);
		}
	}
	return (0);
}