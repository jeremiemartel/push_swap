/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:07:25 by jmartel           #+#    #+#             */
/*   Updated: 2019/02/12 10:07:25 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libps.h>

void	rra(t_push **push)
{
	t_pile	*head;
	t_pile	*buff;

	if (!(*push)->a || !(*push)->a->next)
		return ;
	head = (*push)->a;
	while (head->next)
	{
		buff = head;
		head = head->next;
	}
	buff->next = NULL;
	head->next = (*push)->a;
	(*push)->a = head;
	return ;
}

void	rrb(t_push **push)
{
	t_pile	*head;
	t_pile	*buff;

	if (!(*push)->b || !(*push)->b->next)
		return ;
	head = (*push)->b;
	while (head->next)
	{
		buff = head;
		head = head->next;
	}
	buff->next = NULL;
	head->next = (*push)->b;
	(*push)->b = head;
	return ;
}

void	rrr(t_push **push)
{
	rra(push);
	rrb(push);
}
