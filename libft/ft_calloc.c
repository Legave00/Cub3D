/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:33:08 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/04 20:12:40 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char*)malloc(size * number);
	if (a == NULL)
		return (NULL);
	while (i < number * size)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
