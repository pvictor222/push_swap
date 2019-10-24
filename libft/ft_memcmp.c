/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:13:45 by pvictor           #+#    #+#             */
/*   Updated: 2018/12/23 18:14:11 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buf_s1;
	unsigned char	*buf_s2;
	unsigned int	i;

	buf_s1 = (unsigned char*)s1;
	buf_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (buf_s1[i] != buf_s2[i])
			return (buf_s1[i] - buf_s2[i]);
		i++;
	}
	return (0);
}
