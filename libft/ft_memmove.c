/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:36:31 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 18:00:44 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			d;

	d = -1;
	b = (unsigned char *)dest;
	a = (unsigned char *)src;
	if (a == NULL && b == NULL)
		return (b);
	if (a < b)
	{
		while ((n + 1) > 1)
		{
			b[n - 1] = a[n - 1];
			n--;
		}
	}
	else
	{
		while (++d < n)
			b[d] = a[d];
	}
	return (b);
}
