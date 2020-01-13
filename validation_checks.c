/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:21:31 by mbrogg            #+#    #+#             */
/*   Updated: 2020/01/13 16:22:03 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	mod(int a)
{
	return (a < 0 ? -a : a);
}

char	check_6(short *ar)
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

char	check_3(short *ar)
{
	int		i;

	i = 1;
	while (i < 7)
	{
		if (ar[i + 2] - ar[i] != 1)
			return (0);
		i += 2;
	}
	return (1);
}

char	check_area(short *ar, char i, char j)
{
	int		sum;

	i = 2;
	sum = 0;
	while (i < 8)
	{
		j = 0;
		while (j < i)
		{
			if (mod(ar[(int)i] - ar[(int)j]) == 1 && ar[(int)i + 1] == ar[(int)j + 1])
				sum += 2;
			if (mod(ar[(int)i + 1] - ar[(int)j + 1]) == 1 && ar[(int)i] == ar[(int)j])
				sum += 1;
			j += 2;
		}
		i += 2;
	}
	if (sum > 3 && sum < 6)
		return (1);
	else if (sum == 6)
		return (check_6(ar));
	else if (sum == 3)
		return (check_3(ar));
	else
		return (0);
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
	(*head)->deep = mas[6] - mas[0];
	(*head)->r = max - mas[1];
	(*head)->l = mas[1] - min;
}
