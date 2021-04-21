/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:24:06 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 17:50:32 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*a;
	int		b;

	b = 0;
	if (!s || !f)
		return (NULL);
	i = sizeof(char) * ft_strlen(s) + 1;
	a = malloc(i);
	if (a == NULL)
		return (NULL);
	while (s[b] != '\0')
	{
		a[b] = f(b, s[b]);
		b++;
	}
	a[b] = '\0';
	return (a);
}
