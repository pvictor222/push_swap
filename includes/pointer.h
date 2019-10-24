/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:51:41 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 19:10:35 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A SUPPRIMER ?

#ifndef POINTER_H
# define POINTER_H

typedef	struct		s_function
{
	char			*c;
	void			(*ft)(t_list_ps **begin_list_a, t_list_ps **begin_list_b);

}					t_function;

void				ft_sa(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_sb(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_ss(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_pa(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_pb(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_ra(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_rb(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_rr(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_rra(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_rrb(t_list_ps **begin_list_a, t_list_ps **begin_list_b);
void				ft_rrr(t_list_ps **begin_list_a, t_list_ps **begin_list_b);

t_function			g_function[] =
{
	{"sa", &ft_sa},\
	{"sb", &ft_sb},\
	{"ss", &ft_ss},\
	{"pa", &ft_pa},\
	{"pb", &ft_pb},\
	{"ra", &ft_ra},\
	{"rb", &ft_rb},\
	{"rr", &ft_rr},\
	{"rra", &ft_rra},\
	{"rrb", &ft_rrb},\
	{"rrr", &ft_rrr},\
	{"\0", NULL}\
};

#endif
