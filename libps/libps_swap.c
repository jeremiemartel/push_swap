/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:07:33 by jmartel           #+#    #+#             */
/*   Updated: 2019/02/12 10:07:40 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void		sa(t_push **push)
{
	int		buff;
	t_pile	*pile;

	if (!(*push)->a || !((*push)->a->next))
		return ;
	pile = (*push)->a;
	buff = pile->nb;
	pile->nb = pile->next->nb;
	pile->next->nb = buff;
	return ;
}

void		sb(t_push **push)
{
	int     buff;
	t_pile *pile;

	if (!(*push)->b || !((*push)->b->next))
		return ;
	pile = (*push)->b;
	buff = pile->nb;
	pile->nb = pile->next->nb;
	pile->next->nb = buff;
	return ;
}

void		ss(t_push **push)
{
	sa(push);
	sb(push);
	return ;
}
