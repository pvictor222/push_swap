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

static void	free_avs(int *av2, char **av3)
{
	int		i;

	i = 0;
	free(av2);
	av2 = NULL;
	while (av3[i])
	{
		free(av3[i]);
		av3[i] = NULL;
		i++;
	}
	free(av3);
	av3 = NULL;
}

int			ft_check_error_checker(char **av1, int i)
{
	int		*av2;
	char	**av3;

	if (!(av2 = (int*)ft_memalloc(sizeof(int) * (nb_arg_av(av1) + 1)))
			|| !(av3 = (char**)ft_memalloc(sizeof(char*)
				* (nb_arg_av(av1) + 1))))
		return (0);
	while (++i < nb_arg_av(av1))
	{
		av2[i] = ft_atoi(av1[i]);
		av3[i] = ft_itoa(av2[i]);
		if (ft_strcmp(av3[i], av1[i]) != 0)
		{
			free_avs(av2, av3);
			return (-1);
		}
	}
	av3[i] = NULL;
	if (doublons(av2, nb_arg_av(av1)) != 1)
	{
		free_avs(av2, av3);
		return (-2);
	}
	free_avs(av2, av3);
	return (1);
}
