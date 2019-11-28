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

void				free_new_av(char **new_av)
{
	int				i;

	i = 0;
	while (new_av[i])
	{
		free(new_av[i]);
		i++;
	}
	free(new_av);
}

static void			free_pile(t_list_ps *pile_a)
{
	t_list_ps		*temp;

	temp = pile_a;
	while (temp != NULL)
	{
		pile_a = temp;
		temp = pile_a->next;
		free(pile_a);
		pile_a = NULL;
	}
	free(temp);
	temp = NULL;
}

int					main(int ac, char **av)
{
	t_list_ps		*pile_a;
	t_list_ps		*pile_b;
	char			**new_av;

	if (ac > 1)
	{
		pile_a = NULL;
		pile_b = NULL;
		if (!(new_av = split_av(av)) || ft_check_error(new_av, -1) < 1)
		{
			free_new_av(new_av);
			ft_putendl("Error");
			return (0);
		}
		get_pile_a(new_av, &(pile_a));
		free_new_av(new_av);
		find_algo(&pile_a, &pile_b);
		free_pile(pile_a);
		free_pile(pile_b);
	}
	return (0);
}
