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

	if (ac > 1)
	{
		pile_b = NULL;
		if (!(new_av = split_av(av)) || ft_check_error(new_av) < 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (!(pile_a = get_pile_a(new_av)) || sort_pile(&pile_a, &pile_b) < 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (ft_check_sort(&pile_a, &pile_b) < 1)
		{
			// ft_putendl("KO");
			// printf("\n\nFIN DU GAME CHECKER\n\npile_a : \n\n");
			// print_pile(pile_a);
			// printf("\n\npile_b : \n\n");
			// print_pile(pile_b);
			return (0);
		}
		ft_putendl("OK");
	}
	// printf("\n\nFIN DU GAME CHECKER\n\npile_a : \n\n");
	// print_pile(pile_a);
	// printf("\n\npile_b : \n\n");
	// print_pile(pile_b);
	return (0);
}
