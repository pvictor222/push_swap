/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:51:35 by pvictor           #+#    #+#             */
/*   Updated: 2019/11/25 15:42:31 by pvictor          ###   ########.fr       */
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

t_list_new		*ft_lstnew_new(char *content)
{
	t_list_new	*buf;

	if (!(buf = (t_list_new*)ft_memalloc(sizeof(t_list_new))))
		return (NULL);
	buf->content = ft_strdup(content);
	buf->next = (t_list_new*)NULL;
	return (buf);
}
