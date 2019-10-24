/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:24:48 by pvictor           #+#    #+#             */
/*   Updated: 2019/02/04 16:36:42 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	- On malloc temp et on protege
**	- On read et on stock BUFF_SIZE char sur buff
**	- On join str et buff dans temp
**	- On free str puis str = temp, on free buff
**	- Valeurs de retour :-1 si erreur, ou nb de bytes lus (0 si fini)
*/

static int		read_line(const int fd, char **str)
{
	char		*buff;
	char		*temp;
	int			nb_read;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	nb_read = read(fd, buff, BUFF_SIZE);
	if (nb_read > 0)
	{
		buff[nb_read] = '\0';
		temp = ft_strjoin(*str, buff);
		if (!temp)
			return (-1);
		free(*str);
		*str = temp;
	}
	free(buff);
	return (nb_read);
}

/*
**	- On teste le fd, line et BUFF_SIZE, et on cree str
**	- On fait une boucle qui tourne tant qu'on n'a pas de \n dans str ;
**		- si on a fini la lecture
**			- si str est vide on return 0;
**			- sinon on ajoute \n a la fin pour sortir de la boucle
**		- si erreur return -1
**		- sinon on stoque la fin de ligne dans *end_line
**	- On remplit line
**	- On enleve \n de end_line avec un strdup
**	- On free str puis on l'utilise pour garder end_line en memoire (statique)
*/

int				get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*end_line;
	int			nb_read;

	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, str, 0) < 0 ||
			(!str && (str = ft_strnew(sizeof(*str))) == NULL))
		return (-1);
	while (!(end_line = ft_strchr(str, '\n')))
	{
		if ((nb_read = read_line(fd, &str) == 0))
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (nb_read < 0)
			return (-1);
		else
			end_line = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(end_line));
	end_line = ft_strdup(end_line + 1);
	free(str);
	str = end_line;
	return (1);
}
