/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:22:27 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/01 11:25:55 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void			verline(int drawstart, int drawend, int color, t_bar *a, t_texturka *texturka)
{
	int 		i;
	double		step;
	float		texpos;
	
	i = - 1;
	step = ((double)texturka->hight / (double)a->wall->linehight);
	texpos = (drawstart - (a->sec / 2) + a->wall->linehight / 2) * step;
	while (++i < drawstart)
		mmpp(a, a->x, i, 0x0000A0F0);
	i = drawstart - 1;
	while (++i <= drawend)
	{
		a->texy = (int)texpos & (texturka->hight - 1);
		texpos += step;
		color = *(unsigned int*)(texturka->addr + (a->texy * texturka->ll + a->texx * (texturka->bpp / 8)));
		mmpp(a, a->x, i, color);
	}
	i = drawend - 1;
	while (++i <= a->sec)
		mmpp(a, a->x, i, 0x000F3000);
}

void			mmpp(t_bar *a, int x, int y, int color)
{
	char	*dst;

	dst = a->addr + (y * a->ll + x * (a->bpp / 8));
	*(unsigned int*)dst = color;
}
