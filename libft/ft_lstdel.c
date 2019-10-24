/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:49:56 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/14 11:12:18 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*next;

	if (!alst || !*alst)
		return ;
	temp = *alst;
	if (del != NULL)
	{
		while (temp)
		{
			next = temp->next;
			ft_lstdelone(&temp, del);
			temp = next;
		}
	}
	*alst = NULL;
}
