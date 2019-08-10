/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:14 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:15:19 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_do_op(t_push *push, t_op_id id)
{
	t_list	*new;

	if (!(new = ft_lstnew(t_op_new(id), sizeof(t_op))))
		return (FAILURE);
	ft_lstadd_last(&push->op, new);
	return (SUCCESS);
}

int		ps_error(t_push *push, char *msg)
{
	if (!push || !msg || !push->verbose)
		ft_dprintf(2, "Error\n");
	else
		ft_dprintf(2, "Error: %s\n", msg);
	return (FAILURE);
}

void	*ps_errorn(t_push *push, char *msg)
{
	if (!push || !msg || !push->verbose)
		ft_dprintf(2, "Error\n");
	else
		ft_dprintf(2, "Error: %s\n", msg);
	return (NULL);
}

void	ps_usage(void)
{
	return ;
}
