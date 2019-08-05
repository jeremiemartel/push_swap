/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:07:28 by jmartel           #+#    #+#             */
/*   Updated: 2019/02/12 10:07:41 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ra(t_push **push)
{
	t_pile		*head;
	t_pile		*buff;

	if (!(*push)->a || !(*push)->a->next)
		return ;
	buff = (*push)->a;
	(*push)->a = (*push)->a->next;
	head = (*push)->a;
	while (head->next)
		head = head->next;
	head->next = buff;
	buff->next = NULL;
}

void	rb(t_push **push)
{
	t_pile		*head;
	t_pile		*buff;

	if (!(*push)->b || !(*push)->b->next)
		return ;
	buff = (*push)->b;
	(*push)->b = (*push)->b->next;
	head = (*push)->b;
	while (head->next)
		head = head->next;
	head->next = buff;
	buff->next = NULL;
}

void	rr(t_push **push)
{
	ra(push);
	rb(push);
	return ;
}
