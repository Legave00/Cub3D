/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:30:09 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 06:57:25 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*a;

	i = 0;
	while (str[i])
		i++;
	a = (char *)malloc(i * sizeof(char) + 1);
	if (a == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		a[i] = str[i];
	a[i] = '\0';
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2, int z)
{
	size_t		i;
	size_t		b;
	char		*a;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	b = ft_strlen(s1);
	i = 0;
	a = malloc((b + z) * sizeof(char) + 1);
	if (!a)
		return (NULL);
	while (i < (b + z))
	{
		if (*s1)
			a[i] = *s1++;
		else
			a[i] = *s2++;
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strchr(const char *str, int ch)
{
	char	*a;

	a = (char *)str;
	while (*a != '\0')
	{
		if (*a == ch)
			return (a);
		a++;
	}
	if (ch == '\0')
		return (a);
	return (0);
}

int	ret(int readed, char *ostatok)
{
	if (readed < 0)
	{
		if (*ostatok)
			free(ostatok);
		return (-1);
	}
	if (!ostatok)
		return (0);
	if (ft_strlen(ostatok) != 0)
		free(ostatok);
	ostatok = NULL;
	return (0);
}
