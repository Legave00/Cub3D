/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:53:12 by ydorene           #+#    #+#             */
/*   Updated: 2020/10/31 22:56:46 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			d;

	b = (unsigned char	*)arr1;
	a = (unsigned char	*)arr2;
	d = 0;
	while (d < n)
	{
		if (b[d] == a[d])
			d++;
		else
			return (b[d] - a[d]);
	}
	return (0);
}
