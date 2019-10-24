/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:49:51 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/15 17:13:41 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*buf_s1;
	unsigned char	*buf_s2;

	i = 0;
	buf_s1 = (unsigned char*)s1;
	buf_s2 = (unsigned char*)s2;
	while ((buf_s1[i] == buf_s2[i]) && (i < n))
	{
		if ((buf_s1[i] == '\0') && (buf_s2[i] == '\0'))
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return (buf_s1[i] - buf_s2[i]);
}
