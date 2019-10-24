/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:15:28 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/16 11:38:58 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*buf_dest;
	unsigned char			*buf_src;

	buf_dest = (unsigned char*)dest;
	buf_src = (unsigned char*)src;
	while (n != 0)
	{
		*buf_dest++ = *buf_src;
		if (*buf_src == (unsigned char)c)
			return ((void*)buf_dest);
		buf_src++;
		n--;
	}
	return (NULL);
}
