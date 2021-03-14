/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:26:54 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/05 21:13:30 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		modul(int n)
{
	long int a;

	a = n;
	if (n >= 0)
		return (a);
	else
		return (-a);
}

static char			*zap(long int n, long int i, char *a)
{
	if (n >= 0)
		while (i > 0)
		{
			a[i - 1] = (n % 10 + 48);
			i--;
			n = n / 10;
		}
	else
		while (i > 0)
		{
			a[i] = (-n % 10 + 48);
			i--;
			n = n / 10;
		}
	return (a);
}

char				*ft_itoa(int n)
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
	if (n < 0)
	{
		if ((a = (char*)malloc(sizeof(char) * i + 2)) == NULL)
			return (NULL);
		*a = '-';
		a[i + 1] = '\0';
	}
	else
	{
		if ((a = (char*)malloc(sizeof(char) * i + 1)) == NULL)
			return (NULL);
		a[i] = '\0';
	}
	return (zap(n, i, a));
}
