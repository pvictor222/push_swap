/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:44:31 by pvictor           #+#    #+#             */
/*   Updated: 2018/12/23 17:45:17 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*buf;

	buf = (char*)malloc(sizeof(char) * (size + 1));
	if (!buf)
		return (NULL);
	ft_memset(buf, '\0', size + 1);
	return (buf);
}
