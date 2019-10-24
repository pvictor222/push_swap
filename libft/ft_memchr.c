/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:14:26 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/15 11:14:05 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*buf;

	i = 0;
	buf = (char*)s;
	while (i < n)
	{
		if (buf[i] == (char)c)
			return ((void*)buf + i);
		i++;
	}
	return (NULL);
}
