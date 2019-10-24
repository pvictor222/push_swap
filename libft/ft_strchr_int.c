/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:59:08 by pvictor           #+#    #+#             */
/*   Updated: 2019/01/28 17:05:11 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strchr_int(char *buff, char c)
{
	int		i;

	i = 0;
	if (buff)
	{
		while (buff[i] != '\0')
		{
			if (buff[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}
