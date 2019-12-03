/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:52:17 by pvictor           #+#    #+#             */
/*   Updated: 2019/12/03 18:52:19 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	Print the options if the 'h' tag is on
*/

void		print_help(void)
{
	ft_putendl("List of available options:");
	ft_putendl("        '-h' --> help menue");
	ft_putendl("        '-v' --> verbose mode: details the errors");
	ft_putendl("        '-p' --> prints the unordered list of numbers");
	ft_putendl("        '-c' --> counts the number of movements\n");
}

/*
**	Print the pile given as an argument (option (-p))
*/

void		print_pile(char **av)
{
	int			i;

	i = -1;
	ft_putendl("Unordered list:");
	while (av[++i])
	{
		ft_putstr(av[i]);
		if (av[i + 1])
			ft_putstr(" --> ");
	}
	ft_putendl("\n");
}
