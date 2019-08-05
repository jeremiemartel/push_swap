/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_is_valid_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:15:49 by jmartel           #+#    #+#             */
/*   Updated: 2019/04/27 10:55:01 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static ops		*ck_is_valid_op_2(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (&sa);
	if (ft_strcmp(line, "sb") == 0)
		return (&sb);
	if (ft_strcmp(line, "ss") == 0)
		return (&ss);
	if (ft_strcmp(line, "pa") == 0)
		return (&pa);
	if (ft_strcmp(line, "pb") == 0)
		return (&pb);
	if (ft_strcmp(line, "ra") == 0)
		return (&ra);
	if (ft_strcmp(line, "rb") == 0)
		return (&rb);
	if (ft_strcmp(line, "rr") == 0)
		return (&rr);
	return (NULL);
}
static ops		*ck_is_valid_op_3(char *line)
{
	if (ft_strcmp(line, "rra") == 0)
		return (&rra);
	if (ft_strcmp(line, "rrb") == 0)
		return (&rrb);
	if (ft_strcmp(line, "rrr") == 0)
		return (&rrr);
	return (NULL);
}

ops		*ck_is_valid_op(char *line)
{
	if (!line || !*line)
		return (NULL);
	if (ft_strlen(line) == 2)
		return (ck_is_valid_op_2(line));
	else if (ft_strlen(line) == 3)
		return (ck_is_valid_op_3(line));
	else
		return (NULL);
}
