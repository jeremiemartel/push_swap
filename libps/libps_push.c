/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:07:21 by jmartel           #+#    #+#             */
/*   Updated: 2019/02/12 10:07:22 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	pa(t_push **push)
{
	t_pile		*buff;

	if (!(*push)->b)
		return ;
	buff = (*push)->b;
	(*push)->b = (*push)->b->next;
	buff->next = (*push)->a;
	(*push)->a = buff;
	(*push)->lena++;
	(*push)->lenb--;
	return ;
}

void	pb(t_push **push)
{
	t_pile		*buff;

	if (!(*push)->a)
		return ;
	buff = (*push)->a;
	(*push)->a = (*push)->a->next;
	buff->next = (*push)->b;
	(*push)->b = buff;
	(*push)->lena--;
	(*push)->lenb++;
	return ;
}
