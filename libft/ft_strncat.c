/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:50:08 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/16 11:11:02 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	result = dest;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		result[i] = src[j];
		i++;
		j++;
	}
	result[i] = '\0';
	dest = result;
	return (dest);
}
