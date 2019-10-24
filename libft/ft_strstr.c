/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:37:35 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/15 17:34:14 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*occurence;

	occurence = 0;
	i = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		if (to_find[0] == str[i])
		{
			occurence = (char*)str + i;
			j = 0;
			while (to_find[j] == str[i + j])
			{
				if (to_find[j + 1] == '\0')
					return (occurence);
				j++;
			}
			occurence = 0;
		}
		i++;
	}
	return (NULL);
}
