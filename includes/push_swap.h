/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:08:13 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:15:57 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** malloc, free, exit(3)
*/
# include <stdlib.h>

/*
** read(2), write(2)
*/
# include <unistd.h>

# include "libft.h"
# include "libps.h"

# define SUCCESS	0
# define FAILURE	1

/*
** ps_parsing.c
*/
int			ps_parsing(t_push **push, char **argv);
int			ps_parsing_fill_push(t_push **push, char **argv);
int			ps_parsing_push_list(t_push **push, char *str);
int			ps_parsing_is_number(char *str);
int			ps_parsing_check_duplication(t_push *push);

/*
** ps_sort_select.c
*/
int			ps_sort_select(t_push *push);

/*
** ps_tools.c
*/
int			ps_do_op(t_push *push, t_op_id id);
int			ps_error(t_push *push, char *msg);
void		*ps_errorn(t_push *push, char *msg);
void		ps_usage(void);

#endif