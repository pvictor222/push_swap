/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:51:09 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/16 11:10:20 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (dest[j] && j < size)
		j++;
	while ((src[k]) && ((j + k + 1) < size))
	{
		dest[j + k] = src[k];
		k++;
	}
	if (j != size)
		dest[j + k] = '\0';
	return (j + ft_strlen((char*)src));
}
