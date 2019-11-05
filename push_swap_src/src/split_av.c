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

static void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

static char	**fill_new(char **src, char **to_add)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!(dest = (char**)ft_memalloc(sizeof(char*) * ((nb_arg(to_add))
		+ nb_arg(src) + 2))))
		return (NULL);
	if (src != NULL)
	{
		while (src[i] != NULL)
		{
			dest[i] = ft_strdup(src[i]);
			i++;
		}
	}
	while (to_add[++j] != NULL)
		dest[i++] = ft_strdup(to_add[j]);
	dest[i] = NULL;
	return (dest);
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
		new = fill_new(new, split);
		i++;
	}
	free_split(split);
	return (new);
}
