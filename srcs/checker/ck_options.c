/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:30:28 by jmartel           #+#    #+#             */
/*   Updated: 2019/04/27 10:51:07 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ck_options(t_push *push, int argc, char ***argv)
{
	if (argc <= 1)
		return (ck_error(push, "Too few arguments given"));
	if ((*argv)[1][0] != '-' || (*argv)[1][1] != '-')
		return (SUCCESS);
	if (ft_strchr((*argv)[1], 'h'))
		ck_usage();
	if (argc == 2)
		return (FAILURE);
	if (ft_strchr((*argv)[1], 'g'))
		push->color = 1;
	if (ft_strchr((*argv)[1], 'v'))
		push->verbose = 1;
	if (ft_strchr((*argv)[1], 'c'))
		push->count = 1;
	(*argv)++;
	return (SUCCESS);
	(void)argc;
	(void)argv;
	(void)push;
}
