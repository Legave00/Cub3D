/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:40:44 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/06 00:09:14 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		b;
	size_t		e;
	char		*a;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	b = 0;
	e = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((a = malloc(i * sizeof(char) + 1)) == NULL)
		return (NULL);
	while (b < ft_strlen(s1))
	{
		a[b] = s1[b];
		b++;
	}
	while (b < i)
	{
		a[b] = s2[e];
		b++;
		e++;
	}
	a[i] = '\0';
	return (a);
}
