/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:39:50 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/01 00:12:00 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	b;
	size_t			d;

	d = 0;
	a = (unsigned char *)s;
	b = (unsigned char)c;
	if (n == 0)
		if (a == NULL)
			return (NULL);
	while (d < n)
	{
		a[d] = b;
		d++;
	}
	return (a);
}
