/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:59:24 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/13 18:24:29 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*buf_s1;
	unsigned char	*buf_s2;

	i = 0;
	buf_s1 = (unsigned char*)s1;
	buf_s2 = (unsigned char*)s2;
	while (buf_s1[i] == buf_s2[i])
	{
		if (buf_s1[i] == '\0' && buf_s2[i] == '\0')
			return (0);
		i++;
	}
	return ((buf_s1[i] - buf_s2[i]));
}
