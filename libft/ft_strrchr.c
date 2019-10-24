/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:42:31 by pvictor           #+#    #+#             */
/*   Updated: 2018/12/23 17:43:02 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*buf;

	buf = NULL;
	while (*s)
	{
		if (*s == c)
			buf = s;
		s++;
	}
	if (*s == c)
		buf = s;
	return ((char*)buf);
}
