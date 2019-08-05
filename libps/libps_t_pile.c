/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps_t_pile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:01:05 by jmartel           #+#    #+#             */
/*   Updated: 2019/04/26 15:21:45 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_pile	*t_pile_new(int nb, t_pile *next)
{
	t_pile	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->nb = nb;
	new->next = next;
	return (new);
}

void	t_pile_free(t_pile **pile)
{
	free(*pile);
	pile = NULL;
}

void	t_pile_free_list(t_pile **pile)
{
	t_pile	*head;
	t_pile	*buff;

	if (!pile)
		return ;
	head = *pile;
	while (head)
	{
		buff = head;
		head = head->next;
		t_pile_free(&buff);
	}
	*pile = NULL;
	return ;
}
