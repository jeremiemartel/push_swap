/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:41:13 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/05 20:33:18 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ops_put(t_push *push)
{
	t_pile	*head;

	head = push->op;
	while (head)
	{
		ft_putchar(head->nb % 0xff);
		ft_putchar(head->nb / 0xff00);
		if (head->nb / 0xff0000)
			ft_putchar((head->nb / 0xff0000));
		ft_putchar('\n');
		head = head->next;
	}
}

int		main(int argc, char **argv)
{
	t_push	*push;

	if (argc <= 1)
		return (FAILURE);
	if (!(push = t_push_new()))
		return (ps_error(NULL, NULL));
	push->verbose = 0;
	if (ps_parsing(&push, argv) == FAILURE)
		return (FAILURE);
	if (is_push_sorted(push))
		return (0);
	ps_sort_select(push);
	ps_ops_put(push);
	t_push_free(&push);
	return (0);
	(void)argv;
}
