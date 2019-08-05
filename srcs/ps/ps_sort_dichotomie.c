/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_dichotomie.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:32:27 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/05 20:30:37 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_sort_dichotomie_index(t_pile *pile, int nb)
{
	int		i;

	i = 0;
	while (nb < pile->nb)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

// int			ps_sort_dichotomie_a(t_push *push)
// {
// 	int		i;

// 	i = ps_sort_dichotomie_index(push->b, push->a->nb);
// 	ps_do_op(push, &pb, 'p' + 0xff00 * 'b');
// 	while (i > 0)
// 	{
		
// 		i--;
// 	}
// 	return (SUCCESS);
// }


// int		ps_sort_dichotomie(t_push *push)
// {
// 	while (is_push_sorted(push))
// 	{
// 		if (push->a)
// 			ps_sort_dichotomie_b(push);
// 		if (push->b)
// 			ps_sort_dichotomie_a(push);

// 	}
// 	return (SUCCESS);
// }
