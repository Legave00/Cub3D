/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:03:21 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/05 18:10:58 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;

	a = (const unsigned char*)s1;
	b = (const unsigned char*)s2;
	if (n == 0)
		return (0);
	if (*a == '\0')
		return (-*b);
	else if (*b == '\0')
		return (*a);
	while (n > 1 && *a != '\0' && *b && *a == *b)
	{
		a++;
		b++;
		n--;
	}
	if (*a != *b)
		return (*a - *b);
	return (0);
}
