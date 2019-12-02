/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:30:12 by pvictor           #+#    #+#             */
/*   Updated: 2019/03/25 11:51:16 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstadd_ps(t_list_ps **alst, t_list_ps *new)
{
	if ((new != NULL))
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lstadd_new(t_list_new **alst, t_list_new *new)
{
	if ((new != NULL))
	{
		new->next = *alst;
		*alst = new;
	}
}
