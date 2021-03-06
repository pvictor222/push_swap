/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:38:55 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 10:38:26 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "pointer.h"

void	case_1(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_sa(pile_a, pile_b);
	print_action(prev, "sa");
	ft_rra(pile_a, pile_b);
	print_action(prev, "rra");
}

void	case_2(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_ra(pile_a, pile_b);
	print_action(prev, "ra");
}

void	case_3(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_sa(pile_a, pile_b);
	print_action(prev, "sa");
}

void	case_4(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_rra(pile_a, pile_b);
	print_action(prev, "rra");
	ft_sa(pile_a, pile_b);
	print_action(prev, "sa");
}

void	case_5(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_rra(pile_a, pile_b);
	print_action(prev, "rra");
}
