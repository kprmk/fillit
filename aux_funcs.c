/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:52:44 by eshor             #+#    #+#             */
/*   Updated: 2020/01/13 19:55:39 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_mod(int a)
{
	return (a < 0 ? -a : a);
}

int		ft_sqrt(int nbr)
{
	int result;

	result = 1;
	while (result * result < nbr)
		result++;
	return (result);
}
