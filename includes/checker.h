/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:54:55 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 19:08:25 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

typedef struct			s_list_ps
{
	int					content;
	struct s_list_ps	*next;
}						t_list_ps;

void					ft_sa(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_sb(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_ss(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_pa(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_pb(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_ra(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rb(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rr(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rra(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rrb(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);
void					ft_rrr(t_list_ps **begin_list_a,\
						t_list_ps **begin_list_b);

/*
**	check_sort.c
*/

int						ft_check_sort(t_list_ps **pile_a, t_list_ps **pile_b);

/*
**	check_error.c
*/

int						ft_check_error(char **av1);

/*
**	sort_pile.c
*/
int						sort_pile(t_list_ps **pile_a, t_list_ps **pile_b);

/*
**	ft_lstnew.c
*/

t_list_ps				*ft_lstnew_ps(int content);

/*
**	ft_lstadd.c
*/

void					ft_lstadd_ps(t_list_ps **alst, t_list_ps *new);

/*
**	get_pile.c
*/

t_list_ps				*get_pile_a(char **av);

/*
**	split_ac.c
*/

char					**split_av(char **av);

#endif
