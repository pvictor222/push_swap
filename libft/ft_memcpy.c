/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:12:57 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/16 11:08:38 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*buf_dest;
	const char	*buf_src;

	buf_dest = dest;
	buf_src = src;
	while (n > 0)
	{
		*buf_dest = *buf_src;
		buf_dest++;
		buf_src++;
		n--;
	}
	return (dest);
}
