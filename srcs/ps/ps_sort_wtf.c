/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_wtf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:05:09 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/05 20:30:41 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_sort_wtf_max(int i, int j, int k)
{
	if (i >= j && i >= k)
		return (i);
	if (j >= i && j >= k)
		return (j);
	return (k);
}

int		ps_sort_wtf_last(t_pile *pile)
{
	while (pile->next)
		pile = pile->next;
	return (pile->nb);
}

int		ps_sort_wtf(t_push *push)
{
	int		first;
	int		second;
	int		last;

	while (!is_push_sorted(push))
	{
		while (push->lena > 2)
		{
			first = push->a->nb;
			second = push->a->next->nb;
			last = ps_sort_wtf_last(push->a);
			if (first == ps_sort_wtf_max(first, second, last))
				ps_do_op(push, &pb, 'p' + 'b' * 0xff00);
			else if (second == ft_max(second, last))
			{
				ps_do_op(push, &ra, 'r' + 'a' * 0xff00);
				ps_do_op(push, &pb, 'p' + 'b' * 0xff00);
			}
			else
			{
				ps_do_op(push, &rra, 'r' + 'r' * 0xff00 + 'a' * 0xff0000);
				ps_do_op(push, &pb, 'p' + 'b' * 0xff00);
			}
		}
	}
	return (SUCCESS);
}
