/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:29:34 by ydorene           #+#    #+#             */
/*   Updated: 2021/03/23 16:29:37 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strcpy(char *dst, char *src)
{
	int i;

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
	char *a;

	a = NULL;
	if (*ostatok)
		if ((a = ft_strchr(*ostatok, '\n')))
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
	else
		*line = ft_strdup("");
	return (a);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			readed;
	char		*perehod;
	static char	*ostatok;
	char		*tmp;

	if (!line || fd < 0 || (read(fd, NULL, 0) > 0) || BUFFER_SIZE <= 0)
		return (-1);
	perehod = proverka(&ostatok, line);
	while (!perehod && ((readed = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[readed] = '\0';
		if ((perehod = (ft_strchr(buf, '\n'))))
		{
			*perehod = '\0';
			free(ostatok);
			ostatok = ft_strdup(++perehod);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf, readed);
		free(tmp);
	}
	if (perehod)
		return (1);
	return (ret(readed, ostatok));
}
