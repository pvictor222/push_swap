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

static void			free_pile(t_list_new *pile_a)
{
	t_list_new		*temp;

	temp = pile_a;
	while (temp)
	{
		pile_a = temp;
		free(pile_a->content);
		temp = pile_a->next;
		free(pile_a);
		pile_a = NULL;
	}
	free(temp);
	temp = NULL;
}

static void			fill_list_av(char **split, t_list_new **pile)
{
	int				i;
	t_list_new		*new;

	i = 0;
	new = NULL;
	while (split[i] != NULL)
	{
		new = ft_lstnew_new(split[i]);
		ft_lstadd_new(pile, new);
		i++;
		new = NULL;
	}
}

static char			**fill_new(t_list_new **pile)
{
	int				i;
	char			**dest;
	t_list_new		*temp;

	temp = *pile;
	if (!(dest = (char**)ft_memalloc(sizeof(char*) * (nb_node_new(temp) + 2))))
		return (NULL);
	i = nb_node_new(temp);
	while (i >= -1)
	{
		dest[i + 1] = NULL;
		i--;
	}
	i = nb_node_new(temp);
	dest[i + 1] = NULL;
	while (temp)
	{
		dest[i] = ft_strdup(temp->content);
		temp = temp->next;
		i--;
	}
	return (dest);
}

static void			free_split(char **split)
{
	int				i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

/*
**	On met tous les arguments dans une liste chainee
**	On passe cette liste chainee dans un tableau et on return
*/

char				**split_av(char **av)
{
	int				i;
	char			**new;
	char			**split;
	t_list_new		*pile;

	i = 1;
	new = NULL;
	split = NULL;
	pile = NULL;
	while (av[i] != NULL)
	{
		if (!(split = ft_split_whitespaces(av[i])))
			return (NULL);
		fill_list_av(split, &pile);
		free_split(split);
		split = NULL;
		i++;
	}
	new = fill_new(&pile);
	i = 0;
	free_pile(pile);
	return (new);
}
