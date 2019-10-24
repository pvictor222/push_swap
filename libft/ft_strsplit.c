/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:39:15 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/29 15:21:36 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_c(char *s, char c)
{
	int		i;

	i = 0;
	while ((s[i] != c) && (s[i] != '\0'))
		i++;
	return (i);
}

static char	*ft_strdup_c(const char *s, char c)
{
	char	*dest;
	int		i;

	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen_c((char*)s, c) + 1)))
			|| (!c) || (!s))
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**tab;
	int		i;
	int		j;

	len = ft_count_words((char *)s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (len + 1))) || !s || !c)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && (s[i] != '\0'))
		{
			tab[j] = ft_strdup_c(&s[i], c);
			j++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
