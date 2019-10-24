/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:54:42 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/18 09:54:52 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_words_tables(char **tab)
{
	int		i;
	int		j;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				ft_putchar(tab[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}
