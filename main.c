/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:14:40 by eshor             #+#    #+#             */
/*   Updated: 2020/01/13 19:33:22 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    lst_print(t_lst *head)
{
    int     i;

    i = -1;
    while(head)
    {
        i = -1;
        ft_putnbr(head->index_number);
        ft_putstr("\t->\t");
        while (++i < 4)
        {
            ft_putnbr(head->coords[i]);
            ft_putstr("\t");
        }
        printf("%d %d %d\n", head->l, head->r, head->deep);
        ft_putchar('\n');
        head = head->next;
    }
}

int		main(int argc, char **argv)
{
	t_lst	*head;
	int		amount;

	head = NULL;
	amount = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((amount = validation(argv[1], &head)) < 1)
		ft_putstr("error\n");
	else
	{
		lst_print(head);
		bruteforce(head, amount);
		lst_del(&head);
	}
	return (0);
}
