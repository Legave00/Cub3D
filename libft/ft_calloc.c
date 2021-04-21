/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:33:08 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 18:09:45 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)malloc(size * number);
	if (a == NULL)
		return (NULL);
	while (i < number * size)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
