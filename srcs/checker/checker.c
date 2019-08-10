/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:40:52 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:25:25 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ck_read(t_push *push)
{
	char	*line;
	int		ret;
	t_op	*op;

	line = NULL;
	ret = 1;
	while (get_next_line(0, &line) == 1)
	{
		if (!(op = ck_is_valid_op(line)))
		{
			t_push_free(&push);
			free(line);
			return (ck_error(push, "Invalid operation given"));
		}
		if (push->verbose)
			ft_printf("%s%s%s\n", CYAN, line, EOC);
		free(line);
		op->op(&push);
		if (push->verbose)
			t_push_put(push);
		if (push->count)
			push->count++;
	}
	return (SUCCESS);
}

static void	ck_result(t_push *push)
{
	if (is_push_sorted(push))
	{
		if (push->color)
			ft_printf("%sOK%s\n", GREEN, EOC);
		else
			ft_printf("OK\n");
		if (push->count)
			ft_printf("%s%d operations%s\n", GREEN, push->count - 1, EOC);
	}
	else
	{
		if (push->color)
			ft_printf("%sKO%s\n", RED, EOC);
		else
			ft_printf("KO\n");
	}
}

int		main(int argc, char **argv)
{
	t_push	*push;

	if (argc <= 1)
		return (FAILURE);
	if (!(push = t_push_new()))
		return (FAILURE);
	if (ck_options(push, argc, &argv) == FAILURE)
	{
		t_push_free(&push);
		return (FAILURE);		
	}
	if (ck_parsing(&push, argv) == FAILURE)
	{
		t_push_free(&push);
		return (FAILURE);
	}
	if (ck_read(push) == FAILURE)
		return (FAILURE);
	ck_result(push);
	t_push_free(&push);
	return (SUCCESS);
}
