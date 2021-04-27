/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ostatki.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:53:40 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 06:57:47 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	checkfile(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (i <= 4)
		printerror("неправильное название файла");
	else if (ft_strncmp((s + i - 4), ".cub", 4))
		printerror("неправильное название файла");
}

void	longestline(t_bar *a)
{
	int	i;
	int	num;
	int	len;

	i = a->wall.linest;
	while (a->map[i] && a->map[i][0] == '\0')
		i++;
	a->wall.linemap = i;
	i = a->wall.linest;
	num = -1;
	while (i < a->size)
	{
		len = ft_strlen(a->map[i++]);
		if (len > num)
			num = len;
	}
	a->wall.longest = num;
}
