/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_is_valid_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:15:49 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:24:44 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_op	*ck_is_valid_op(char *line)
{
	t_op_id		index;
	t_op		*op;

	index = 0;
	if (!line || !*line)
		return (NULL);
	while (index < OP_ID_LEN)
	{
		op = t_op_get_address(index);
		if (ft_strequ(line, op->name))
			return (op);
		index++;
	}
	return (NULL);
}
