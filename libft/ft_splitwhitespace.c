/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:44:43 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 14:32:19 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_number_words(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\n'
					|| str[i] == '\t') && str[i] != '\0')
			i++;
		while (str[i] != ' ' && str[i] != '\n'
				&& str[i] != '\t')
		{
			if (str[i] == '\0')
				return (j + 1);
			i++;
		}
		j++;
	}
	return (j);
}

int		ft_length_word(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

char	*ft_strdup_split(char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_length_word(src);
	dest = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != ' ' && src[i] != '\t' && src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_whitespaces(char *str)
{
	int		len;
	char	**tab;
	int		i;
	int		j;

	len = ft_number_words(str);
	tab = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
		{
			tab[j] = ft_strdup_split(&str[i]);
			j++;
			while (str[i] != '\n' && str[i] != ' '
					&& str[i] != '\t' && str[i] != '\0')
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
