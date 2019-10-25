/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:25:15 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 18:58:04 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct			s_list_ps
{
	int					content;
	struct s_list_ps	*next;
}						t_list_ps;

/*
**	get_pile.c
*/

t_list_ps				*get_pile_a(char **av);

/*
**	ft_lstadd.c
*/

void					ft_lstadd_ps(t_list_ps **alst, t_list_ps *new);

/*
**	ft_lstnew.c
*/

t_list_ps				*ft_lstnew_ps(int content);

/*
**	split_ac.c
*/

char					**split_av(char **av);

/*
**	check_error.c
*/

int						ft_check_error(char **av1);

/*
**	check_sort.c
*/

int						ft_check_sort(t_list_ps **pile_a, t_list_ps **pile_b);
int						ft_check_sort_a(t_list_ps **pile_a);
int						ft_check_sort_b(t_list_ps **pile_b);
int						check_next_node(t_list_ps **pile_a, t_list_ps **pile_b);

/*
**	find_min_max.c
*/

void					find_min(t_list_ps **pile_a, int *pos);
int						find_max_pos(t_list_ps **pile_a, int *pos, int i);
int						find_max(t_list_ps **pile);

/*
**	find_mediane.c
*/

int						find_mediane(t_list_ps *pile, int size_to_sort);
int						find_q1(t_list_ps *pile, int size_to_sort);

/*
**	ope_a.c
*/

void					push_a(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);
void					rotate_a(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);
void					rev_a(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);

/*
**	ope_b.c
*/

void					push_b(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);
void					rotate_b(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);
void					rev_b(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);

/*
**	empty_b.c
*/

void					empty_b(t_list_ps **pile_a, t_list_ps **pile_b,\
						int i, int pos, char **prev);

/*
**	empty_a_big.c
*/

void					empty_a_big(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);

/*
**	sort_small.c
*/

void					sort_small(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);

/*
**	sort_three.c
*/

void					sort_three(t_list_ps **pile_a, t_list_ps **pile_b);

/*
**	sort_three_cases.c
*/

void					case_1(t_list_ps **pile_a, t_list_ps **pile_b);
void					case_2(t_list_ps **pile_a, t_list_ps **pile_b);
void					case_3(t_list_ps **pile_a, t_list_ps **pile_b);
void					case_4(t_list_ps **pile_a, t_list_ps **pile_b);
void					case_5(t_list_ps **pile_a, t_list_ps **pile_b);

/*
**	find_algo.c
*/

void					sort_two(t_list_ps **pile_a, t_list_ps **pile_b);
void					find_algo(t_list_ps **pile_a, t_list_ps **pile_b);
int						nb_node(t_list_ps *pile);
void					print_action(char **prev, char *next);

/*
**	sort_default.c
*/

void					sort_default(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);
void					empty_last_a(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);
void					push_below(t_list_ps **pile_a, t_list_ps **pile_b,
						int mediane, int max, char **prev);

/*
**	sort_big.c
*/

void					sort_big(t_list_ps **pile_a, t_list_ps **pile_b, char **prev);

/*
**	swap.c
*/

void					ft_sa(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_sb(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_ss(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);

/*
**	push.c
*/

void					ft_pa(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_pb(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);

/*
**	rotate.c
*/

void					ft_ra(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rb(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rr(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);

/*
**	rev_rotate.c
*/

void					ft_rra(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rrb(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rrr(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);

#endif
