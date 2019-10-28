/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:33:23 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 14:51:02 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	nb_arg_av(char **av)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

static int	doublons(int *av, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (av[i] == av[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_check_error(char **av1)
{
	int		*av2;
	char	**av3;
	int		i;

	i = 0;
	if (!(av2 = (int*)ft_memalloc(sizeof(char) * nb_arg_av(av1)))
			|| !(av3 = (char**)ft_memalloc(sizeof(char*) * nb_arg_av(av1))))
		return (0);
	while (i < nb_arg_av(av1))
	{
		av2[i] = ft_atoi(av1[i]);
		av3[i] = ft_itoa(av2[i]);
		if (ft_strcmp(av3[i], av1[i]) != 0)
			return (-1);
		i++;
	}
	free(av2);
	free(av3);
	if (doublons(av2, nb_arg_av(av1)) != 1)
		return (-2);
	return (1);
}
