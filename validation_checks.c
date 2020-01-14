/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:21:31 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/14 16:05:35 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	check_4(short *ar)
{
	int	i;

	i = 0;
	if (ar[i] == ar[i + 2] && ar[i + 4] == ar[i + 6])
		return (1);
	while (i < 6)
	{
		if (ar[i + 2] - ar[i] != 1)
			return (0);
		i += 2;
	}
	return (1);
}

char	check_adjacent(short *ar, int sum)
{
	if (sum == 3)
		return (1);
	else if (sum == 4)
		return (check_4(ar));
	else
		return (0);
}

char	check_area(short *ar, int i, int j)
{
	int		sum;

	i = 2;
	sum = 0;
	while (i < 8)
	{
		if (ar[(int)i] == -1)
			return (0);
		j = 0;
		while (j < i)
		{
			if (ar[(int)i] - ar[(int)j] == 1
				&& ar[(int)i + 1] == ar[(int)j + 1])
				sum += 1;
			if (ft_mod(ar[(int)i + 1] - ar[(int)j + 1]) == 1
				&& ar[(int)i] == ar[(int)j])
				sum += 1;
			j += 2;
		}
		i += 2;
	}
	return (check_adjacent(ar, sum));
}

void	deep_and_hor(t_lst **head, short *mas)
{
	short	min;
	short	max;
	char	i;

	i = 3;
	min = mas[1];
	max = mas[1];
	while (i <= 7)
	{
		if (mas[(int)i] < min)
			min = mas[(int)i];
		if (mas[(int)i] > max)
			max = mas[(int)i];
		i += 2;
	}
	(*head)->r = max - mas[1];
	(*head)->l = mas[1] - min;
}
