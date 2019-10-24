/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:34:04 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/15 14:00:21 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen((char*)s);
	if (!(dest = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	if (!(s[i] == '\n' || s[i] == '\t' || s[i] == ' ' ||
				s[j - 1] == '\n' || s[j - 1] == '\t' || s[j - 1] == ' '))
		return (ft_strdup((char*)s));
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
		dest[j++] = s[i++];
	dest[j] = '\0';
	j--;
	while (dest[j] == ' ' || dest[j] == '\t' || dest[j] == '\n')
		dest[j--] = '\0';
	return (dest);
}
