/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:51:17 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/01 02:42:49 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *a;

	a = (char *)str;
	while (*a != '\0')
	{
		if (*a == ch)
			return (a);
		a++;
	}
	if (ch == '\0')
		return (a);
	return (0);
}