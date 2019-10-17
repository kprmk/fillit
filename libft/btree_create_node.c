/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:30:28 by mbrogg            #+#    #+#             */
/*   Updated: 2019/08/16 09:48:35 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*res;

	res = (t_btree *)malloc(sizeof(t_btree));
	if (res)
	{
		res->item = item;
		res->left = 0;
		res->right = 0;
	}
	return (res);
}
