/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:26:05 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/15 16:11:08 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_lst(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		ft_putstr((char*)temp->content);
		ft_putchar('\n');
		temp = temp->next;
	}
}
