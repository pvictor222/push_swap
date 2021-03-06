/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:04:21 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 14:50:45 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		check_trim(char *str)
{
	int			i;

	i = -1;
	if (!str || !str[0])
		return (-1);
	while (str[++i])
		if (str[i] != ' ')
			return (1);
	return (-1);
}

static char		**verbose_av(char **new_av)
{
	int			i;
	char		**ret;

	if (!(ret = (char**)ft_memalloc(sizeof(char*) * (nb_elem(new_av) + 1))))
		return (NULL);
	i = 0;
	while (new_av[i + 1])
	{
		ret[i] = ft_strdup(new_av[i + 1]);
		i++;
	}
	ret[i] = NULL;
	free_str_tab(new_av);
	return (ret);
}

/*
**	Tag list:
**	1. v --> error verbose
**	2. p --> print the piles
**	3. c --> count the number of movements
**	4. vp
**	5. vc
**	6. pc
**	7. vpc
**	h --> help: displays the tag options
*/

static int		optio(char *tag, int mode)
{
	if (ft_strchr(tag, '-'))
	{
		if (ft_strchr(tag, 'v'))
			mode = 1;
		if (ft_strchr(tag, 'p'))
			mode = (mode == -1) ? 2 : 4;
		if (ft_strchr(tag, 'c'))
		{
			if (mode == -1)
				mode = 3;
			else
			{
				if (mode == 2)
					mode = 6;
				else if (mode == 1)
					mode = 5;
				else
					mode = 7;
			}
		}
		if (ft_strchr(tag, 'h'))
			print_help();
	}
	return (mode);
}

static void		handle_av(t_list_ps *pile_a, t_list_ps *pile_b,
	char **new_av, int mode)
{
	if (ft_check_error_checker(new_av, -1) == -1)
		ft_putendl((mode <= 0) ? "Error" : "Error: must be numbers");
	else if (ft_check_error_checker(new_av, -1) == -2)
		ft_putendl((mode <= 0) ? "Error" : "Error: repeated arguments");
	else if (!(pile_a = get_pile_a_checker(new_av))
		|| sort_pile(&pile_a, &pile_b, mode, 0) < 1)
	{
		ft_putendl((mode <= 0) ? "Error" : "Error: wrong instructions");
		free_piles(&pile_a, &pile_b);
	}
	else
	{
		if (mode == 2 || mode == 4 || mode == 6 || mode == 7)
			print_pile(new_av);
		if (ft_check_sort(&pile_a, &pile_b) >= 1)
			ft_putendl("OK");
		else
			ft_putendl("KO");
		free_piles(&pile_a, &pile_b);
	}
}

/*
**	ALGO | Memo.
**	1 = sa --> swap the first 2 elements of a
**	2 = sb --> swap the first 2 elements of b
**	3 = ss --> sa + sb
**	4 = pa --> push the first element of b on top of a
**	5 = pb --> push the first element of a on top of b
**	6 = ra --> rotate a : the top element of a becomes the last
**	7 = rb --> rotate b : the top element of b becomes the last
**	8 = rr --> ra + rb
**	9 = rra --> reverse rotate a : the last element of a becomes the top
**	10 = rrb --> reverse rotate b : the last element of b becomes the top
**	11 = rrr --> rra + rrb
**	-----
**	MAIN
**	- Verifications des arguments et split_whitespaces
**	- On recupere la pile et on applique l'algo
**	- On verifie que la pile est bien triee
*/

int				main(int ac, char **av)
{
	t_list_ps	*pile_a;
	t_list_ps	*pile_b;
	char		**new_av;
	int			mode;

	mode = 0;
	if (!(ac == 1 || av[1] == NULL || !av[1] || ft_strcmp(av[1], "") == 0)
		|| (ac == 2 && check_trim(av[1]) == -1))
	{
		if (!(new_av = split_av(av)))
		{
			ft_putendl("Error");
			free(new_av);
			return (0);
		}
		else if (check_trim(av[1]) != -1 && (mode = optio(new_av[0], -1)) >= 1)
			new_av = verbose_av(new_av);
		pile_a = NULL;
		pile_b = NULL;
		handle_av(pile_a, pile_b, new_av, mode);
		free_str_tab(new_av);
	}
	return (0);
}
