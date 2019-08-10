/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_t_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:51:14 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:20:49 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_op		*t_op_get_address(t_op_id id)
{
	static t_op		op[11] = {
		{E_PA, &pa, "pa"},
		{E_PB, &pb, "pb"},
		{E_SA, &sa, "sa"},
		{E_SB, &sb, "sb"},
		{E_SS, &ss, "ss"},
		{E_RA, &ra, "ra"},
		{E_RB, &rb, "rb"},
		{E_RR, &rr, "rr"},
		{E_RRA, &rra, "rra"},
		{E_RRB, &rrb, "rrb"},
		{E_RRR, &rrr, "rrr"},
	};

	return (&op[id]);
}

t_op		*t_op_new(t_op_id id)
{
	return (t_op_get_address(id));
}
