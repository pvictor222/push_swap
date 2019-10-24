/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:10:09 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/18 09:50:58 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buf;

	if (s)
	{
		i = 0;
		buf = s;
		while (i < n)
		{
			buf[i] = (unsigned char)c;
			i++;
		}
		return (s);
	}
	return (NULL);
}
