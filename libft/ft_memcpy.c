/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:02 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/01 02:59:26 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			c;

	c = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (b == 0)
		if (a == NULL)
			return (NULL);
	while (c < n)
	{
		a[c] = b[c];
		c++;
	}
	return (a);
}
