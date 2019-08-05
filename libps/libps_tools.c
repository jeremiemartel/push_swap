/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:26:54 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/05 20:29:03 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		is_pile_sorted(t_pile *pile)
{
	while (pile->next)
	{
		if (pile->nb > pile->next->nb)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int		is_push_sorted(t_push *push)
{
	t_pile	*head;

	if (push->b != NULL)
		return (0);
	head = push->a;
	while (head->next)
	{
		if (head->nb > head->next->nb)
			return (0);
		head = head->next;
	}
	return (1);
}
