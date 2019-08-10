/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:46:26 by jmartel           #+#    #+#             */
/*   Updated: 2019/08/10 13:24:59 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "libps.h"

# define SUCCESS	0
# define FAILURE	1

/*
** Number of valid operations
*/
#define CK_OP_LEN	11

/*
** ck_options.c
*/
int			ck_options(t_push *push, int argc, char ***argv);

/*
** ck_parsing.c
*/
int			ck_parsing(t_push **push, char **argv);
int			ck_parsing_fill_push(t_push **push, char **argv);
int			ck_parsing_push_list(t_push **push, char *str);
int			ck_parsing_is_number(char *str);
int			ck_parsing_check_duplication(t_push *push);

/*
** ck_is_valid_op.c
*/
t_op		*ck_is_valid_op(char *line);

/*
** ck_do_op.c
*/
int			ck_do_op(t_push *push, char *line);

/*
** ck_tools.c
*/
int			ck_error(t_push *push, char *msg);
void		*ck_errorn(t_push *push, char *msg);
void		ck_usage(void);

#endif