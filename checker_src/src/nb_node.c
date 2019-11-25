/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:37:57 by pvictor           #+#    #+#             */
/*   Updated: 2019/11/25 15:40:24 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		nb_node_new(t_list_new *pile_a)
{
	int			i;
	t_list_new	*temp;

	i = 0;
	temp = pile_a;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
