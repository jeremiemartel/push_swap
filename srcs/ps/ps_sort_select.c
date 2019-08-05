/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:20 by jmartel           #+#    #+#             */
/*   Updated: 2019/04/27 16:05:46 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ps_sort_select_mintotop_a(t_push *push)
{
	int		min;
	int		index;
	t_pile	*pile;

	pile = push->a;
	min = pile->nb;
	index = 0;
	while (pile)
	{
		if (pile->nb < min)
			min = pile->nb;
		index++;
		pile = pile->next;
	}
	if (index < (push->lena / 2))
	{
		while (push->a->nb != min)
			ps_do_op(push, &ra, 'r' + 'a' * 0xff00);
	}
	else
	{
		while (push->a->nb != min)
			ps_do_op(push, &rra, 'r' + 'r' * 0xff00 + 'a' * 0xff0000);
	}
	ps_do_op(push, &pb, 'p' + 'b' * 0xff00);
	return (min);
}

int				ps_sort_select(t_push *push)
{
	while (push->lena > 0)
		ps_sort_select_mintotop_a(push);
	while (push->lenb > 0)
		ps_do_op(push, &pa, 'p' + 'a' * 0xff00);
	return (SUCCESS);
}
