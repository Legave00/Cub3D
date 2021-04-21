/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:29:34 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/15 19:15:07 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	if (!src || !dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*proverka(char **ostatok, char **line)
{
	char	*a;

	a = NULL;
	if (*ostatok)
	{
		a = ft_strchr(*ostatok, '\n');
		if (a)
		{
			*a = '\0';
			*line = ft_strdup(*ostatok);
			*ostatok = ft_strcpy(*ostatok, ++a);
		}
		else
		{
			*line = ft_strdup(*ostatok);
			**ostatok = '\0';
		}
	}
	else
		*line = ft_strdup("");
	return (a);
}

int	get_next_line(int fd, char **line)
{
	t_gnl		a;
	static char	*ostatok;

	if (!line || fd < 0 || (read(fd, NULL, 0) > 0) || BUFFER_SIZE <= 0)
		return (-1);
	a.perehod = proverka(&ostatok, line);
	a.readed = 1;
	while (!a.perehod && a.readed > 0)
	{
		a.readed = read(fd, a.buf, BUFFER_SIZE);
		a.buf[a.readed] = '\0';
		a.perehod = ft_strchr(a.buf, '\n');
		if (a.perehod)
		{
			*a.perehod = '\0';
			free(ostatok);
			ostatok = ft_strdup(++a.perehod);
		}
		a.tmp = *line;
		*line = ft_strjoin(*line, a.buf, a.readed);
		free(a.tmp);
	}
	if (a.perehod)
		return (1);
	return (ret(a.readed, ostatok));
}
