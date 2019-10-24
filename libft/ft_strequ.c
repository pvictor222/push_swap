/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:56:12 by pvictor           #+#    #+#             */
/*   Updated: 2018/12/23 17:56:37 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char	*buf_s1;
	char	*buf_s2;

	buf_s1 = (char*)s1;
	buf_s2 = (char*)s2;
	if (buf_s1 && buf_s2 && (ft_strcmp(buf_s1, buf_s2) == 0))
		return (1);
	return (0);
}
