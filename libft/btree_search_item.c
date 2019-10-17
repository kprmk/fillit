/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:52:30 by mbrogg            #+#    #+#             */
/*   Updated: 2019/08/16 22:27:25 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (root)
	{
		if (cmpf(root->item, data_ref) > 0)
			return (btree_search_item(root->left, data_ref, cmpf));
		else if (!cmpf(root->item, data_ref))
			return (root->item);
		else
			return (btree_search_item(root->right, data_ref, cmpf));
	}
	else
		return (0);
}
