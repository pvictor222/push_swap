/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:11:08 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/20 18:31:20 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	Checks that pile_a is ordered and pile_b is empty
*/

int				ft_check_sort_a(t_list_ps **pile_a)
{
	t_list_ps	*temp;

	temp = *pile_a;
	while (temp && temp->next)
	{
		if (temp->content >= temp->next->content)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

/*
**	Checks that pile_b is ordered
*/

int				ft_check_sort_b(t_list_ps **pile_b)
{
	t_list_ps	*temp;

	temp = *pile_b;
	while (temp && temp->next)
	{
		if (temp->content != 1 + temp->next->content)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

/*
**	Checks that pile_a is ordered and pile_b is empty
*/

int				ft_check_sort(t_list_ps **pile_a, t_list_ps **pile_b)
{
	if (*pile_b || ft_check_sort_a(pile_a) == -1)
		return (-1);
	return (1);
}

/*
**	Checks whether the last or the first element of pile_b is the next element
**	to add on pile_a
**	--> returns 1 if it is the first element, 2 if it is the last, -1 otherwise
*/

int				check_next_node(t_list_ps **pile_a, t_list_ps **pile_b)
{
	t_list_ps	*temp;

	temp = *pile_b;
	if (ft_check_sort_a(pile_a) == 1)
	{
		if ((*pile_a)->content == 1 + (*pile_b)->content)
			return (1);
		else
		{
			while (temp->next)
				temp = (temp)->next;
			if ((*pile_a)->content == (1 + temp->content))
				return (2);
			else
				return (-1);
		}
	}
	else
		return (-1);
}
