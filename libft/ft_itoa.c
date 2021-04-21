/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:26:54 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 18:19:13 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	modul(int n)
{
	long int	a;

	a = n;
	if (n >= 0)
		return (a);
	else
		return (-a);
}

static char	*zap(long int n, long int i, char *a)
{
	if (n >= 0)
	{
		while (i > 0)
		{
			a[i - 1] = (n % 10 + 48);
			i--;
			n = n / 10;
		}
	}
	else
	{
		while (i > 0)
		{
			a[i] = (-n % 10 + 48);
			i--;
			n = n / 10;
		}
	}
	return (a);
}

static char	*mal(int n, long int i)
{
	char	*a;

	if (n < 0)
	{
		a = (char *)malloc(sizeof(char) * i + 2);
		if (a == NULL)
			return (NULL);
		*a = '-';
		a[i + 1] = '\0';
	}
	else
	{
		a = (char *)malloc(sizeof(char) * i + 1);
		if (a == NULL)
			return (NULL);
		a[i] = '\0';
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char			*a;
	long int		i;
	long int		s;

	i = 1;
	s = modul(n);
	while (s > 9)
	{
		i++;
		s = s / 10;
	}
	a = mal(n, i);
	return (zap(n, i, a));
}
