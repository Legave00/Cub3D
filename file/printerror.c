/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:34:15 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 06:57:47 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	printerror(char *s)
{
	printf("%s\n", s);
	exit(0);
}

char	*runspace(char *s)
{
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	return (s);
}

int	runline(char **s, int i)
{
	while (s[i] && s[i][0] == '\0')
		i++;
	return (i);
}

void	checkway(t_tex *tex, t_tur *tur)
{
	if (!tex->imgn || !tex->imgso)
		printerror("невалидный путь");
	if (!tur->imgw || !tur->imge)
		printerror("невалидный путь");
}

void	rescheck(t_bar *a, double w, double h, int i)
{
	if (w > 2560)
		a->w = 2560;
	if (h > 1440)
		a->h = 1440;
	if (w == 0 || h == 0 || i > 2)
		printerror("некорректное разрешение");
}
