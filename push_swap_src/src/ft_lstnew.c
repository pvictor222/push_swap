/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:51:35 by pvictor           #+#    #+#             */
/*   Updated: 2019/03/25 11:51:57 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list_ps		*ft_lstnew_ps(int content)
{
	t_list_ps	*buf;

	if (!(buf = (t_list_ps*)ft_memalloc(sizeof(t_list_ps))))
		return (NULL);
	buf->content = content;
	buf->next = (t_list_ps*)NULL;
	return (buf);
}
