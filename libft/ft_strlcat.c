/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:07:30 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 17:51:18 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	size_t	ln(char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *str, size_t size)
{
	size_t	i;
	size_t	b;
	size_t	c;

	i = ln(dst);
	c = ln(dst);
	b = 0;
	if (size < i + 1)
		return (ln(str) + size);
	while (b < (size - c - 1) && str[b] != '\0')
	{
		dst[i] = str[b];
		i++;
		b++;
	}
	dst[i] = '\0';
	return (ln(str) + c);
}
