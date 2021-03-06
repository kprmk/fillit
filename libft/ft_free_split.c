/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 23:35:39 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/20 23:35:41 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_split(char **ar, size_t i)
{
	size_t	j;

	j = 0;
	while (j != i)
	{
		free(ar[j]);
		j++;
	}
	free(ar);
	return (NULL);
}
