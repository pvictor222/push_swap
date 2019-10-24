/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:14:36 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 18:36:24 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nb_arg(char **av)
{
	int		i;

	if (av == NULL)
		return (0);
	i = 0;
	while (av[i] != NULL)
		i++;
	return (i + 1);
}

static char	**fill_new(char **new_old, char **to_add, int i)
{
	char	**new_new;
	int		j;

	j = -1;
	if (!(new_new = (char**)ft_memalloc(sizeof(char*) * ((nb_arg(to_add))
						+ nb_arg(new_old) + 2))))
		return (NULL);
	if (new_old != NULL)
	{
		while (new_old[i] != NULL)
		{
			new_new[i] = ft_strdup(new_old[i]);
			i++;
		}
	}
	while (to_add[++j] != NULL)
	{
		if (!(new_new[i] = (char*)ft_memalloc(sizeof(char)
						* (ft_strlen(to_add[j]) + 1))))
			return (NULL);
		new_new[i++] = ft_strdup(to_add[j]);
	}
	new_new[i] = NULL;
	return (new_new);
}

char		**split_av(char **av)
{
	int		i;
	char	**new;
	char	**split;

	i = 1;
	new = NULL;
	split = NULL;
	while (av[i] != NULL)
	{
		split = ft_split_whitespaces(av[i]);
		new = fill_new(new, split, 0);
		i++;
	}
	return (new);
}
