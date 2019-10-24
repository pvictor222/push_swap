/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:11:08 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/17 18:09:05 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				ft_check_sort(t_list_ps **pile_a, t_list_ps **pile_b)
{
	t_list_ps	*temp;

	if (!*pile_a)
		return (-1);
	temp = *pile_a;
	while (temp->next)
	{
		if (temp->content >= temp->next->content || *pile_b)
			return (-1);
		temp = temp->next;
	}
	return (1);
}
