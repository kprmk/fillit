/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:21:31 by mbrogg            #+#    #+#             */
/*   Updated: 2019/12/21 23:33:24 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	mod(int a)
{
	return (a < 0 ? -a : a);
}

char	check_6(char *ar)
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

char	check_3(char *ar)
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

char	check_point_spot(char *ar, int i)
{
	int		res;

	res = 0;
	if (ar[i + 1] < 4)
	{
		if (ar[i] < 4)
		{
			if (ar[i + 2] - ar[i] == 1 && ar[i + 1] == ar[i + 3])
				res += 2;
			if (ar[i + 2] == ar[i] && ar[i + 3] - ar[i + 1] == 1)
				res += 1;
			if (ar[i + 4] - ar[i] == 1 && ar[i + 1] == ar[i + 5])
				res += 2;
			if (ar[i + 4] == ar[i] && ar[i + 5] - ar[i + 1] == 1)
				res += 1;
		}
	}
	return (res);
}

char	check_area(char *ar)
{
	int		sum;
	int		i;
	int		j;

	i = 2;
	sum = 0;
	while (i < 8)
	{
		j = 0;
		while (j < i)
		{
			if (mod(ar[i] - ar[j]) == 1 && ar[i + 1] == ar[j + 1])
				sum += 2;
			if (mod(ar[i + 1] - ar[j + 1]) == 1 && ar[i] == ar[j])
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
