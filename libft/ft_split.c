/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:48:00 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 19:47:08 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f1(const char *s, char c)
{
	size_t	i;
	int		b;

	i = 0;
	b = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			b++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (b);
}

static char	*f3(char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
		s++;
	return (s);
}

static char	*f2(char *a, char c)
{
	int		i;
	char	*b;
	int		d;

	i = 0;
	d = 0;
	while (a[i] != c && a[i] != '\0')
		i++;
	b = malloc(sizeof(char) * (i + 1));
	if (b == NULL)
		return (NULL);
	while (d < i)
	{
		b[d] = a[d];
		d++;
	}
	b[d] = '\0';
	return (b);
}

static void	freeall(char **a, int d)
{
	while (d >= 0)
	{
		if (a[d])
			free(a[d]);
		d--;
	}
}

char	**ft_split(char const *b, char c)
{
	t_all	x;

	x.d = 0;
	x.a = (char **)malloc(sizeof(char *) * (f1(b, c) + 1));
	if (!b || x.a == NULL)
		return (NULL);
	while (*b != '\0')
	{
		if (*b != c)
		{
			x.a[x.d] = f2(b, c);
			if (x.a[x.d] == NULL)
			{
				freeall(x.a, x.d - 1);
				free(x.a);
				return (NULL);
			}
			x.d++;
			b = f3(b, c);
		}
		else
			b++;
	}
	x.a[x.d] = NULL;
	return (x.a);
}
