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


// // Fonction pour afficher une pile, à supprimer
// #include <stdio.h>
// static void print_pile(t_list_ps *pile)
// {
// 	t_list_ps *temp = pile;
// 	while (temp)
// 	{
// 		printf("%d ", (temp)->content);
// 		temp = (temp)->next;
// 	}
// 	printf("\n");
// }

char			**verbose_av(char **new_av)
{
	int			i;

	i = 0;
	while (new_av[i + 1])
	{
		new_av[i] = new_av[i + 1];
		i++;
	}
	new_av[i] = NULL;
	return(new_av);
}

// void			ft_free_av(char ***new_av)
// {
// 	int			i;

// 	i = 0;
// 	while (new_av[i])
// 	{
// 		free(new_av[i]);
// 		i++;
// 	}
// 	free(new_av);
// }

// void			ft_free_piles(t_list_ps **pile_a, t_list_ps **pile_b)
// {
// 	t_list_ps	*temp;
// 	while (*pile_a) {
// 		free(*pile_a);
// 		temp = *pile_a;
// 		*pile_a = (*pile_a)->next;
// 		free(temp);
// 	}
// 	free(*pile_a);
// 	(void)pile_b;
// }

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
	int			error_mode;

	error_mode = 0;
	if (!(ac == 1 || av[1] == NULL || !av[1] || ft_strcmp(av[1], "") == 0))
	{
		pile_b = NULL;
		if (!(new_av = split_av(av)))
		{
			ft_putendl((error_mode == 0) ? "Error" : "Error: invalid arguments");
			return (0);
		}
		else if (ft_strcmp(new_av[0], "-v") == 0) {
			error_mode = 1;
			new_av = verbose_av(new_av);
		}
		if (ft_check_error(new_av) == -1)
			ft_putendl((error_mode == 0) ? "Error" : "Error: arguments must be numbers");
		else if (ft_check_error(new_av) == -2)
			ft_putendl((error_mode == 0) ? "Error" : "Error: repeated arguments");
		else if (!(pile_a = get_pile_a(new_av)) || sort_pile(&pile_a, &pile_b) < 1) {
			ft_putendl((error_mode == 0) ? "Error" : "Error: wrong instructions");
		}
		else if (ft_check_sort(&pile_a, &pile_b) >= 1) {
			ft_putendl("OK");
		}
		else {
			ft_putendl("KO");
		}
	}
	return (0);
}
