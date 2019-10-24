/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:00:10 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 18:29:21 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int ac, char **av)
{
	t_list_ps		*pile_a;
	t_list_ps		*pile_b;
	char			**new_av;

	if (ac > 1)
	{
		pile_b = NULL;
		if (!(new_av = split_av(av)) || ft_check_error(new_av) < 1)
		{
			ft_putendl("Error");
			return (0);
		}
		if (!(pile_a = get_pile_a(new_av)))
		{
			return (0);
		}
		find_algo(&pile_a, &pile_b);
	}
	return (0);
}
