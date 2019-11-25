/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_a_big.c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:57:53 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 18:50:04 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_decile_min(t_list_ps **pile_a)
{
	t_list_ps	*temp;
	int			min;

	temp = *pile_a;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

static int		calc_decile(int *tab, int size, int dec_number)
{
	if (size % 2)
		return (tab[(int)(size * dec_number / 12) + 1]\
			+ tab[(int)(size * dec_number / 12)]);
	else
		return (tab[(int)(size * dec_number / 12)]);
}

static int		find_decile(t_list_ps *pile_a, int dec_number, int size_to_sort)
{
	t_list_ps	*temp;
	int			*tab;
	int			i;
	int			decile;

	i = 0;
	temp = pile_a;
	if (!(tab = (int*)ft_memalloc(sizeof(int) * (size_to_sort + 1))))
		return (0);
	while (temp && i < size_to_sort)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_integer_tab(tab, i - 1);
	decile = calc_decile(tab, i, (dec_number + 1));
	free(tab);
	return (decile);
}

static void		find_10_deciles(t_list_ps **pile_a, int **deciles)
{
	int			i;

	i = 0;
	(*deciles)[0] = find_decile_min(pile_a);
	while (i < 10)
	{
		(*deciles)[i] = find_decile(*pile_a, i, nb_node(*pile_a));
		i++;
	}
	(*deciles)[10] = find_max(pile_a);
}

void			empty_a_big(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	int			*deciles;
	int			i;
	int			tab[2];

	if (!(deciles = (int*)ft_memalloc(sizeof(int) * 13)))
		return ;
	deciles[11] = '\0';
	i = 0;
	find_10_deciles(pile_a, &(deciles));
	while (i < 11)
	{
		tab[0] = (deciles[i] / 2);
		tab[1] = deciles[i];
		push_below(pile_a, pile_b, tab, prev);
		i++;
	}
	free(deciles);
}
