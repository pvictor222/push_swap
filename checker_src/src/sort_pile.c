/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:54:52 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/20 18:23:21 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "pointer.h"

static int	check_algo(char *algo)
{
	int		i;

	i = 0;
	if (ft_strcmp(algo, "") == 0)
		return (0);
	while (i < 12)
	{
		if (ft_strcmp(g_function[i].c, algo) == 0)
			return (1);
		i++;
	}
	return (0);
}

int			sort_pile(t_list_ps **pile_a, t_list_ps **pile_b, int mode,
			int nb_actions)
{
	char	*algo;
	int		i;

	algo = NULL;
	while (get_next_line(0, &algo) == 1)
	{
		i = 0;
		if (check_algo(algo) < 1)
		{
			free(algo);
			return (-1);
		}
		while (strcmp(g_function[i].c, algo) != 0)
			i++;
		g_function[i].ft(pile_a, pile_b);
		nb_actions++;
		free(algo);
		algo = NULL;
	}
	if (mode == 3 || mode == 5 || mode == 6 || mode == 7)
	{
		ft_putnbr(nb_actions);
		ft_putendl(" movements\n");
	}
	return (1);
}
