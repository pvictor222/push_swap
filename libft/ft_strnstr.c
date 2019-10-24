/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:43:26 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/15 09:46:22 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	int		j;
	int		occurence;

	occurence = 0;
	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i < (int)len)
	{
		if (to_find[0] == str[i])
		{
			occurence = i;
			j = 0;
			while (to_find[j] == str[i + j])
			{
				if ((to_find[j + 1] == '\0') && ((i + j + 1) <= (int)len))
					return ((char*)&str[occurence]);
				j++;
			}
			occurence = 0;
		}
		i++;
	}
	return (NULL);
}
