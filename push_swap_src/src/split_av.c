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

static int		nb_node_new(t_list_new *pile_a)
{
	int			i;
	t_list_new	*temp;

	i = 0;
	temp = pile_a;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

static void		fill_list_av(char **split, t_list_new **pile)
{
	int			i;
	t_list_new	*new;

	i = 0;
	while (split[i] != NULL)
	{
		new = ft_lstnew_new(split[i]);
		ft_lstadd_new(pile, new);
		i++;
	}
}

static void			free_pile(t_list_new *pile_a)
{
	t_list_new		*temp;

	temp = pile_a;
	while (temp)
	{
		pile_a = temp;
		temp = pile_a->next;
		free(pile_a);
		pile_a = NULL;
	}
	free(temp);
}

static char		**fill_new(t_list_new **pile)
{
	int			i;
	char		**dest;
	t_list_new	*temp;

	temp = *pile;
	if (!(dest = (char**)ft_memalloc(sizeof(char*) * (nb_node_new(temp) + 1))))
		return (NULL);
	i = nb_node_new(temp);
	dest[nb_node_new(temp) + 1] = NULL;
	while (temp)
	{
		dest[i] = ft_strdup(temp->content);
		temp = temp->next;
		i--;
	}
	return (dest);
}

static void		free_split(char **split)
{
	int			i;

	i = 0;
	while (split[i])
	{
		// free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

/*
**	On met tous les arguments dans une liste chainee
**	On passe cette liste chainee dans un tableau et on return
*/

char			**split_av(char **av)
{
	int			i;
	char		**new;
	char		**split;
	t_list_new	*pile;

	i = 1;
	new = NULL;
	split = NULL;
	pile = NULL;
	while (av[i] != NULL)
	{
		split = ft_split_whitespaces(av[i]);
		fill_list_av(split, &pile);
		free_split(split);
		i++;
	}
	new = fill_new(&pile);
	free_pile(pile);
	return (new);
}
