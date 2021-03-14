/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:13:07 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/05 17:57:42 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *c, int ch)
{
	char	*a;
	char	*str;

	str = (char *)c;
	a = NULL;
	if (ch == '\0')
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (*str != '\0')
	{
		if (*str == ch)
		{
			a = str;
		}
		str++;
	}
	return (a);
}
