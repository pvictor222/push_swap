/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:51:35 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/14 10:14:31 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*buf;

	if (!(buf = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		buf->content_size = 0;
		buf->content = NULL;
	}
	else
	{
		if (!(buf->content = malloc(content_size)))
			return (NULL);
		ft_memmove(buf->content, content, content_size);
		buf->content_size = content_size;
	}
	buf->next = NULL;
	return (buf);
}
