/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:13:27 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/20 19:42:51 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*a;

	i = -1;
	a = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (a == NULL)
		return (NULL);
	while (str[++i] != '\0')
		a[i] = str[i];
	a[i] = '\0';
	return (a);
}
