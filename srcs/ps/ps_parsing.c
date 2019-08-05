/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:07:06 by jmartel           #+#    #+#             */
/*   Updated: 2019/04/27 12:57:31 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ps_parsing:
**	main function used to parse argv received by the programm
*/

int			ps_parsing(t_push **push, char **argv)
{
	if (!*argv)
		return (ps_error(*push, "No arguments given"));
	if (ps_parsing_fill_push(push, argv) == FAILURE)
		return (FAILURE);
	if (ps_parsing_check_duplication(*push) == FAILURE)
		return (ps_error(*push, "Duplication detected"));
	return (SUCCESS);
}

/*
** ps_parsing_fill_push:
**	Browse argv to check that every number is valid, then add it to A stack
*/

int			ps_parsing_fill_push(t_push **push, char **argv)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	while (argv[i])
	{
		if (!(tab = ft_split_whitespaces(argv[i])))
			return (ps_error(*push, "Internal Error"));
		j = 0;
		while (tab[j])
		{
			if (ps_parsing_is_number(tab[j]) == FAILURE)
				return (ps_error(*push, "Bad format detected"));
			if (ps_parsing_push_list(push, tab[j]) == FAILURE)
				return (ps_error(*push, "Number is too big"));
			j++;
		}
		(*push)->lena += j;
		ft_strtab_free(tab);
		i++;
	}
	return (SUCCESS);
}

/*
** ps_parsing_push_list:
**	If any valid number had been detected, it will create the t_pile structure,
**	and push it to the end of the A stack. Static variable is used to stock
**	last link created.
**	return SUCCESS or FAILURE
*/

int			ps_parsing_push_list(t_push **push, char *str)
{
	static t_pile	*pile = NULL;
	int				toi;
	long			tol;

	toi = ft_atoi(str);
	tol = ft_atol(str);
	if ((long)toi != tol)
		return (FAILURE);
	if (!pile)
	{
		if (!(pile = t_pile_new(toi, NULL)))
			return (FAILURE);
		(*push)->a = pile;
		return (SUCCESS);
	}
	if (!(pile->next = t_pile_new(toi, NULL)))
		return (FAILURE);
	pile = pile->next;
	return (SUCCESS);
}

/*
** ps_parsing_is_number:
**	Check if number is valid : digit only string,
**	can be stored as an integer, it can be positive or negative
**	return SUCCESS or FAILURE
*/

int			ps_parsing_is_number(char *str)
{
	int		i;

	i = 0;
	if (!*str)
		return (FAILURE);
	if ((*str == '-' || *str == '+') && str[1])
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

/*
** ps_parsing_check_duplication:
**	Look for any duplicate number in the A stack
**	return SUCCESS of FAILURE
*/

int			ps_parsing_check_duplication(t_push *push)
{
	t_pile	*head;
	t_pile	*buff;
	int		nb;

	if (!push || !(buff = push->a))
		return (FAILURE);
	while (buff->next)
	{
		head = buff->next;
		nb = buff->nb;
		while (head)
		{
			if (nb == head->nb)
				return (FAILURE);
			head = head->next;
		}
		buff = buff->next;
	}
	return (SUCCESS);
}
