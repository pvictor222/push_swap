/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:46:49 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/17 10:45:20 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			get_pile_a(char **av, t_list_ps **pile_a)
{
	int			i;
	t_list_ps	*new;

	i = 0;
	(*pile_a) = NULL;
	while (av[i] != NULL)
		i++;
	while (--i >= 0)
	{
		new = ft_lstnew_ps(ft_atoi(av[i]));
		ft_lstadd_ps(pile_a, new);
	}
}

t_list_ps		*get_pile_a_checker(char **av)
{
	int			i;
	t_list_ps	*pile;
	t_list_ps	*new;

	i = 0;
	pile = NULL;
	while (av[i] != NULL)
		i++;
	while (--i >= 0)
	{
		new = ft_lstnew_ps(ft_atoi(av[i]));
		ft_lstadd_ps(&pile, new);
	}
	return (pile);
}