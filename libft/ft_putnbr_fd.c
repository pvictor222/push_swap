/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:04:22 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/15 11:00:37 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int tab[10];
	int *pointeur;

	pointeur = tab;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (n != 0)
	{
		*pointeur = n % 10;
		if (*pointeur < 0)
			*pointeur = *pointeur * (-1);
		pointeur++;
		n = n / 10;
	}
	while (pointeur > tab)
	{
		pointeur--;
		ft_putchar_fd(*pointeur + '0', fd);
	}
}
