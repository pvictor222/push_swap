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

static void			free_new_av(char **new_av)
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
	t_list_ps		*head;

	temp = pile_a;
	head = pile_a;
	while (temp)
	{
		pile_a = temp;
		temp = pile_a->next;
		// ft_putnbr(pile_a->content);
		// ft_putendl("");
		free(pile_a);
		pile_a = NULL;
	}
	free(temp);
}

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
			free_new_av(new_av);
			ft_putendl("Error");
			return (0);
		}
		if (!(pile_a = get_pile_a(new_av)))
		{
			free_new_av(new_av);
			return (0);
		}
		find_algo(&pile_a, &pile_b);
		free_new_av(new_av);
		free_pile(pile_a);
	}
	return (0);
}
