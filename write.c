/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:22:27 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/21 19:03:09 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void	verline(t_wall *wall, t_bar *a, t_texturka *texturka)
{
	int			i;
	int			color;
	double		step;
	float		texpos;

	i = -1;
	step = ((double)texturka->hight / (double)a->wall.linehight);
	texpos = (wall->drawstart - (a->sec / 2) + a->wall.linehight / 2) * step;
	while (++i < wall->drawstart)
		mmpp(a, a->x, i, 0x0000A0F0);
	i = wall->drawstart - 1;
	while (++i <= wall->drawend)
	{
		a->texy = (int)texpos & (texturka->hight - 1);
		texpos += step;
		color = *(unsigned int *)(texturka->addr
				+ (a->texy * texturka->ll + a->texx * (texturka->bpp / 8)));
		mmpp(a, a->x, i, color);
	}
	i = wall->drawend - 1;
	while (++i <= a->sec)
		mmpp(a, a->x, i, 0x000F3000);
}

void	mmpp(t_bar *a, int x, int y, int color)
{
	char	*dst;

	if (x < a->fir && y < a->sec)
	{
		dst = a->win.addr + (y * a->win.ll + x * (a->win.bpp / 8));
		*(unsigned int *)dst = color;
	}
}
