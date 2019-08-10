/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:34:20 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:16:22 by jmartel          ###   ########.fr       */
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
			ps_do_op(push, E_RA);
	}
	else
	{
		while (push->a->nb != min)
			ps_do_op(push, E_RRA);
	}
	ps_do_op(push, E_PB);
	return (min);
}

int				ps_sort_select(t_push *push)
{
	while (push->lena > 0)
		ps_sort_select_mintotop_a(push);
	while (push->lenb > 0)
		ps_do_op(push, E_PA);
	return (SUCCESS);
}
