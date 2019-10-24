/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:52:49 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/14 16:20:51 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new_elem;
	t_list	*begin;

	if (!f || !lst)
		return (NULL);
	temp = f(lst);
	if (!(new_elem = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	lst = lst->next;
	begin = new_elem;
	while (lst)
	{
		temp = f(lst);
		if (!(new_elem->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		new_elem = new_elem->next;
		lst = lst->next;
	}
	return (begin);
}
