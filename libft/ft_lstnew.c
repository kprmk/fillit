/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:44:02 by mbrogg            #+#    #+#             */
/*   Updated: 2019/09/17 10:54:12 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	if (!content)
	{
		res->data = NULL;
		res->size = 0;
	}
	else if (content_size)
	{
		res->data = ft_memalloc(content_size);
		ft_memcpy(res->data, content, content_size);
		res->size = content_size;
	}
	res->next = NULL;
	return (res);
}
