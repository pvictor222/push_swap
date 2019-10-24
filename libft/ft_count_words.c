/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:34:52 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/16 10:45:52 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !c)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		while (str[i] != c)
		{
			if (str[i] == '\0')
				return (j + 1);
			i++;
		}
		j++;
	}
	return (j);
}
