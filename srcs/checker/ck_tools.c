/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:14 by jmartel           #+#    #+#             */
/*   Updated: 2019/04/27 12:59:44 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ck_error(t_push *push, char *msg)
{
	if (!push || !msg || !push->verbose)
		ft_dprintf(2, "Error\n");
	else
		ft_dprintf(2, "Error: %s\n", msg);
	return (FAILURE);
}

void	*ck_errorn(t_push *push, char *msg)
{
	if (!push || !msg || !push->verbose)
		ft_dprintf(2, "Error\n");
	else
		ft_dprintf(2, "Error: %s\n", msg);
	return (NULL);
}

void	ck_usage(void)
{
	ft_printf("./checker [--gvch] numbers\n");
	ft_printf("\th : show usage\n");
	ft_printf("\tg : enable colorization\n");
	ft_printf("\tc : enable counter\n");
	ft_printf("\tv : enable verbose mode\n");
}
