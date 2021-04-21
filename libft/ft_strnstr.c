/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:23:38 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 17:49:43 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	a;

	if (!ft_strlen(little))
		return ((char *)big);
	if (len == 0)
		return (NULL);
	a = ft_strlen(little);
	if (a > ft_strlen(big))
		return (NULL);
	i = len - a + 1;
	while (i--)
	{
		if (!(ft_strncmp(big, little, a)))
			return ((char *)big);
		else
			big++;
	}
	return (0);
}
