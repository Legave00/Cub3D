/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:18:48 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 18:03:59 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	unsigned char		e;

	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	e = (unsigned char)c;
	if (a == NULL && b == NULL)
		return (a);
	while (n)
	{
		*a = *b;
		a++;
		if (*b == e)
			return ((void *)a);
		b++;
		n--;
	}
	return (NULL);
}
