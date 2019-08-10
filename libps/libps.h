/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:07:47 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:22:03 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

#include <stdlib.h>
#include "libft.h"

typedef struct  s_pile
{
	int				nb;
	struct s_pile	*next;
}               t_pile;

typedef struct	s_push
{
	struct s_pile	*a;
	struct s_pile	*b;
	t_list			*op;
	int				lena;
	int				lenb;
	int				lenop;
	int				verbose;
	int				color;
	int				count;
}               t_push;

# define OP_ID_LEN	11

typedef enum	e_op_id
{
	E_PA = 0,
	E_PB,
	E_SA,
	E_SB,
	E_SS,
	E_RA,
	E_RB,
	E_RR,
	E_RRA,
	E_RRB,
	E_RRR
}				t_op_id;

typedef	struct	s_op
{
	t_op_id		id;
	void		(*op)(t_push**push);
	char		name[4];
}				t_op;

typedef void (ops)(t_push **);

/*
** libps_push.c
*/
void			pa(t_push **push);
void			pb(t_push **push);

/*
** libps_swap.c
*/
void			sa(t_push **push);
void			sb(t_push **push);
void			ss(t_push **push);

/*
** libps_rotate.c
*/
void			ra(t_push **push);
void			rb(t_push **push);
void			rr(t_push **push);

/*
** libps_reverse_rotate.c
*/
void			rra(t_push **push);
void			rrb(t_push **push);
void			rrr(t_push **push);

/*
** libps_t_push.c
*/
t_push			*t_push_new(void);
void			t_push_free(t_push **push);
t_pile			*t_push_new_op_push(int nb, t_push *push);
void			t_push_put(t_push *push);

/*
** libps_t_pile.c
*/
t_pile			*t_pile_new(int nb, t_pile *next);
void			t_pile_free(t_pile **pile);
void			t_pile_free_list(t_pile **pile);

/*
** libps_t_op.c
*/
t_op			*t_op_get_address(t_op_id id);
t_op			*t_op_new(t_op_id id);

/*
** libps_tools.c
*/
int			is_pile_sorted(t_pile *pile);
int			is_push_sorted(t_push *push);

#endif
