/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 10:57:52 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 12:21:59 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// // stdio a supprimer
// // Fonction pour afficher une pile, à supprimer
// void print_pile(t_list_ps **pile)
// {
// 	t_list_ps *temp = *pile;
// 	while (temp)
// 	{
// 		printf("%d ", (temp)->content);
// 		temp = (temp)->next;
// 	}
// 	printf("\n");
// }

/*
**	Fonction pour vider la pile_a : tant que a n'est pas triée ou qu'on a pas
**		trois élements seulement, on envoie tout ce qui est inférieur au pivot
**		sur pile_b.
**	return = le nombre de noeuds envoyés sur b
*/

void			empty_a_qs(t_list_ps **pile_a, t_list_ps **pile_b,
				char **prev, int **pivots)
{
	int			stop;
	int			i;

	// printf("\n**** ON VIDE A ****\n");
	(*pivots)[3] = 0;
	i = 0;
	stop = (*pile_a)->content;
	rotate_a(pile_a, pile_b, prev);
	while (ft_check_sort_a(pile_a) != 1 && nb_node(*pile_a) > 3
		&& (*pile_a)->content != stop)
	{
		if ((*pile_a)->content < (*pivots)[0])
		{
			if ((*pivots)[3] == 0)
			{
				(*pivots)[3] = 1;
				(*pivots)[1] = (*pile_a)->content;
			}
			push_b(pile_a, pile_b, prev);
		}
		else {
			i++;
			rotate_a(pile_a, pile_b, prev);
		}
	}
	push_b(pile_a, pile_b, prev);
	while (--i >= 0)
		rev_a(pile_a, pile_b, prev);
	// printf("\n++++ ON A BIEN VIDE A et le nouveau pivot de b est %d ++++\n", (*pivots)[1]);
}

void			empty_b_qs(t_list_ps **pile_a, t_list_ps **pile_b,
				char **prev, int **pivots)
{
	int			stop;
	int			i;

	// printf("\n**** ON VIDE B ****\n");
	stop = (*pile_b)->content;
	i = 0;
	if (ft_check_sort_b(pile_b) == 1)
	{
		while (*pile_b)
			push_a(pile_a, pile_b, prev);
		return ;
	}
	rotate_b(pile_a, pile_b, prev);
	// printf("****PIVOT IN EMPTY B : %d****\n", (*pivots)[1]);
	// printf("\n\npile_a : \n\n");
	// print_pile(pile_a);
	// printf("\n\npile_b : \n\n");
	// print_pile(pile_b);
	// printf("\n++++ ON A BIEN VIDE B ++++\n");
	while ((*pile_b)->content != stop)
	{
		if ((*pile_b)->content > (*pivots)[1])
		{
			if ((*pivots)[2] == 0)
			{
				(*pivots)[2] = 1;
				(*pivots)[0] = (*pile_b)->content;
			}
			push_a(pile_a, pile_b, prev);
		}
		else
			rotate_b(pile_a, pile_b, prev);
	}
	push_a(pile_a, pile_b, prev);
	// printf("\n\nPILE B AVANT\n\npile_a : \n\n");
	// print_pile(pile_a);
	// printf("\n\npile_b : \n\n");
	// print_pile(pile_b);
	while (--i >= 0)
		rev_b(pile_a, pile_b, prev);
	// printf("\n\nPILE B APRES\n\npile_a : \n\n");
	// print_pile(pile_a);
	// printf("\n\npile_b : \n\n");
	// print_pile(pile_b);
	// printf("\n++++ ON A BIEN VIDE B ++++\n");
}

static void		send_next_a(t_list_ps **pile_a, t_list_ps **pile_b,
				char **prev, int **pivots)
{
	// printf("\n\npile_a : \n\n");
	// 	print_pile(pile_a);
	// 	printf("\n\npile_b : \n\n");
	// 	print_pile(pile_b);
	if (check_next_node(pile_a, pile_b) == 1)
	{
		if (*pile_b)
		{
			if ((*pile_b)->content && (*pivots)[1] == (*pile_b)->content)
				(*pivots)[1] = (*pivots)[1] - 1;
			push_a(pile_a, pile_b, prev);
		}
	}
	else
	{
		if (*pile_b)
		{
			rev_b(pile_a, pile_b, prev);
			if ((*pile_b)->content && (*pivots)[1] == (*pile_b)->content)
				(*pivots)[1] = (*pivots)[1] - 1;
			push_a(pile_a, pile_b, prev);
		}
	}
}

/*
**	Description TBD
// Description TBD
*/

void			quicksort(t_list_ps **pile_a, t_list_ps **pile_b, char **prev,
				int **pivots)
{
	// On utilise le premier element de la pile comme pivot, mais on peut
	// envisager de prendre la mediane pour optimiser
	/*
	int			pivot;

	pivot = find_mediane(*pile_a, nb_node(*pile_a));
	*/

	if ((*pivots)[3] == 0) {
		(*pivots)[0] = (*pile_a)->content;
		// printf("FUTUR PIVOT DE A : %d\n", (*pivots)[0]);
	}
	if (ft_check_sort(pile_a, pile_b) == 1)  {
		// printf("\nICI ICI %d ICI ICI\n", 1);
		return;
	}
	else if (ft_check_sort_a(pile_a) == 1 && check_next_node(pile_a, pile_b) != -1)
		send_next_a(pile_a, pile_b, prev, pivots);
	else if (nb_node(*pile_a) <= 3 && ft_check_sort_a(pile_a) == -1) {
		// printf("\nICI ICI %d ICI ICI\n", 5);
		sort_three(pile_a, pile_b);
	}
	else if (nb_node(*pile_a) > 3 && ft_check_sort_a(pile_a) == -1) {
		// printf("\nICI ICI %d ICI ICI\n", 3);
		empty_a_qs(pile_a, pile_b, prev, pivots);
	}
	else if ((*pile_b) && ft_check_sort_a(pile_a) == 1) {
		// printf("\nICI ICI %d ICI ICI\n", 4);
		empty_b_qs(pile_a, pile_b, prev, pivots);
	}
	if (ft_check_sort(pile_a, pile_b) != 1)
	{
		// printf("\n\npile_a : \n\n");
		// print_pile(pile_a);
		// printf("\n\npile_b : \n\n");
		// print_pile(pile_b);
		quicksort(pile_a, pile_b, prev, pivots);
	}
	else {
		// ft_putendl(*prev);

	// printf("\n\nFIN DU GAME\n\npile_a : \n\n");
	// print_pile(pile_a);
	// printf("\n\npile_b : \n\n");
	// print_pile(pile_b);
}
	
	/*
	// Lorsque pile_a est triée et pile_b est vide
	if (ft_check_sort(pile_a, pile_b) == 1)
	{
		ft_putendl(*prev);
		return ;
	}
	*/
}


// SORT_BIG
/*
void			quicksort(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	while (ft_check_sort(pile_a, pile_b) != 1)
	{
		// Pas sur que ce cas la soit super utile --> a checker
		if (ft_check_sort(&((*pile_a)->next->next), pile_b) == 1
				&& (*pile_a)->content < (*pile_a)->next->next->content
				&& (*pile_a)->next->content < (*pile_a)->next->next->content)
		{
			sort_two(pile_a, pile_b);
			return ;
		}
		empty_a_big(pile_a, pile_b, prev);
		sort_three(pile_a, pile_b);
		empty_b(pile_a, pile_b, 0, 0, prev);
		while (ft_check_sort(pile_a, pile_b) != 1)
			rev_a(pile_a, pile_b, prev);
	}
	ft_putendl(*prev);
}
*/