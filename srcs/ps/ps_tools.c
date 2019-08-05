/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:14 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/05 20:30:48 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_do_op(t_push *push, ops f, int nb)
{
	if (!(t_push_new_op_push(nb, push)))
		return (FAILURE);
	f(&push);
	push->lenop++;
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
