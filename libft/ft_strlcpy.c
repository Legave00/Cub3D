/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:29:08 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/04 15:37:42 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *str, size_t size)
{
	size_t i;

	i = 0;
	if (!dst && !str)
		return (0);
	if (size == 0)
		return (ft_strlen(str));
	while (i < (size - 1) && str[i] != '\0')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(str));
}
