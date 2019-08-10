/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_t_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:01:40 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:17:48 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_push	*t_push_new(void)
{
	t_push	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->a = NULL;
	new->b = NULL;
	new->op = NULL;
	new->verbose = 0;
	new->color = 0;
	new->count = 0;
	new->lena = 0;
	new->lenb = 0;
	new->lenop = 0;
	return (new);
}

void	t_push_free(t_push **push)
{
	t_pile_free_list(&((*push)->a));
	t_pile_free_list(&((*push)->b));
	ft_lstdel(&((*push)->op), NULL);
	free(*push);
	push = NULL;
	return ;
}

void	t_push_put(t_push *push)
{
	t_pile	*head_a;
	t_pile	*head_b;

	head_a = push->a;
	head_b = push->b;
	while (head_a || head_b)
	{
		if (head_a)
		{
			ft_printf("%-12d", head_a->nb);
			head_a = head_a->next;
		}
		else
			ft_printf("%12c", ' ');
		if (head_b)
		{
			ft_printf("%-12d", head_b->nb);
			head_b = head_b->next;
		}
		else
			ft_printf("%12c", ' ');
		ft_putchar('\n');
	}
}
