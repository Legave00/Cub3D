/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:43:20 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 17:49:25 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*f1(const char *s1, int a, int b, char *c)
{
	int	i;
	int	d;

	i = a;
	d = 0;
	while (i >= a && i < b)
	{
		c[d] = s1[i];
		d++;
		i++;
	}
	return (c);
}

static int	f2(const char *s1, const char *set)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	b = 0;
	a = 0;
	while (set[a] != '\0' && s1[i] != '\0')
	{
		if (s1[i] == set[a])
		{
			b++;
			i++;
			a = 0;
		}
		else
			a++;
	}
	return (b);
}

static int	f3(const char *s1, const char *set)
{
	int		i;
	int		a;
	int		b;

	i = ft_strlen(s1);
	b = 0;
	a = 0;
	while (set[a] != '\0')
	{
		if (s1[i - 1] == set[a])
		{
			b++;
			i--;
			a = 0;
		}
		else
			a++;
	}
	return (b);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	int		i;
	int		b;

	if (!s1 || !set)
		return (NULL);
	if (f2(s1, set) == (int)ft_strlen(s1))
		return (ft_strdup(""));
	i = sizeof(char) * (ft_strlen(s1) - f2(s1, set) - f3(s1, set)) + 1;
	b = ft_strlen(s1) - f3(s1, set);
	a = malloc(i);
	if (a == NULL)
		return (NULL);
	f1(s1, f2(s1, set), b, a);
	a[i - 1] = '\0';
	return (a);
}
