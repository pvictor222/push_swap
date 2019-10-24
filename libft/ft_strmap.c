/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:47:56 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/13 18:29:50 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	i = 0;
	if (s && f)
	{
		if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
			return (NULL);
		else
		{
			while (s[i])
			{
				dest[i] = (*f)(s[i]);
				i++;
			}
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
