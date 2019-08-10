/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:41:13 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:26:51 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ops_put(t_push *push)
{
	t_list	*head;
	t_op	*op;

	head = push->op;
	while (head)
	{
		op = (t_op*)(head->content);
		ft_printf("%s\n", op->name);
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
