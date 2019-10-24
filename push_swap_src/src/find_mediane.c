/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:52:38 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 18:15:52 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		calc_mediane(int *tab, int size)
{
	if (size % 2)
		return ((tab[(size / 2) + 1] + tab[size / 2]) / 2);
	else
		return (tab[size / 2]);
}

int				find_mediane(t_list_ps *pile, int size_to_sort)
{
	t_list_ps	*temp;
	int			*tab;
	int			i;
	int			mediane;

	i = 0;
	temp = pile;
	if (!(tab = (int*)ft_memalloc(sizeof(int) * (size_to_sort + 1))))
		return (0);
	while (temp && i < size_to_sort)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_integer_tab(tab, i - 1);
	mediane = calc_mediane(tab, i);
	return (mediane);
}

static int		calc_q1(int *tab, int size)
{
	if (size % 2)
		return (tab[(int)(size / 4) + 1] + tab[(int)(size / 4)]);
	else
		return (tab[(int)(size / 4)]);
}

int				find_q1(t_list_ps *pile, int size_to_sort)
{
	t_list_ps	*temp;
	int			*tab;
	int			i;
	int			q1;

	i = 0;
	temp = pile;
	if (!(tab = (int*)ft_memalloc(sizeof(int) * (size_to_sort + 1))))
		return (0);
	while (temp && i < size_to_sort)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_integer_tab(tab, i - 1);
	q1 = calc_q1(tab, i);
	return (q1);
}
