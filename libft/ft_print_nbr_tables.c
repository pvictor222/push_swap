/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_tables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:02:31 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/15 15:20:15 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_nbr_tables(int const *tab, size_t size)
{
	unsigned long	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		i++;
		ft_putchar('\n');
	}
}
