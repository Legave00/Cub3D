/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:20:13 by ydorene           #+#    #+#             */
/*   Updated: 2021/03/31 22:15:02 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void			wall(t_bar *a, t_player *player, t_ray *ray)
{
	int		h;

	h = a->sec;
	if (ray->side == 0)
		ray->perp = (a->player->xp - a->player->posx + (1 - ray->stepx) / 2)
		/ ray->raydirx;
	else
		ray->perp = (a->player->yp - a->player->posy + (1 - ray->stepy) / 2)
		/ ray->raydiry;
	a->wall->linehight = (h / ray->perp);
	a->wall->drawstart = -a->wall->linehight / 2 + h / 2;
	if (a->wall->drawstart < 0)
		a->wall->drawstart = 0;
	a->wall->drawend = a->wall->linehight / 2 + h / 2;
	if (a->wall->drawend >= h)
		a->wall->drawend = h - 1;
	if (a->ray->side == 0)
		a->wallx = player->posy + ray->perp * ray->raydiry;
	else
		a->wallx = player->posx + ray->perp * ray->raydirx;
	a->wallx -= floor((a->wallx));
	sidetex(a, a->ray, a->player);
	text(a);
	verline(a->wall->drawstart, a->wall->drawend, 0x00FFA07A, a, a->texturka);
}

void			runray(t_bar *a)
{
	a->player->xp = (int)a->player->posx;
	a->player->yp = (int)a->player->posy;
	a->ray->hit = 0;
	while (a->ray->hit == 0)
	{
		if (a->ray->sidedistx < a->ray->sidedisty)
		{
			a->ray->sidedistx += a->ray->deltadistx;
			a->player->xp += a->ray->stepx;
			a->ray->side = 0;
		}
		else
		{
			a->ray->sidedisty += a->ray->deltadisty;
			a->player->yp += a->ray->stepy;
			a->ray->side = 1;
		}
		if (a->map[a->player->yp][a->player->xp] == '1')
			a->ray->hit = 1;
	}
	wall(a, a->player, a->ray);
}

void			ft_ray(t_bar *a, t_player *player, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (player->posx -
		(int)player->posx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = ((int)player->posx + 1 -
		player->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (player->posy -
		(int)player->posy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = ((int)player->posy + 1 -
		player->posy) * ray->deltadisty;
	}
	runray(a);
}

void			delta(t_bar *a, t_player *player)
{
	if (a->ray->raydiry == 0)
		a->ray->deltadistx = 0;
	else if (a->ray->raydirx == 0)
		a->ray->deltadistx = 1;
	else
		a->ray->deltadistx = fabs(1 / a->ray->raydirx);
	if (a->ray->raydirx == 0)
		a->ray->deltadisty = 0;
	else if (a->ray->raydiry == 0)
		a->ray->deltadisty = 1;
	else
		a->ray->deltadisty = fabs(1 / a->ray->raydiry);
	ft_ray(a, a->player, a->ray);
}

void			paint(int i, t_bar *a)
{
	int	b;

	b = 0;
	while (a->map[i])
	{
		b = 0;
		while (a->map[i][b])
		{
			if (a->map[i][b] == 'N' || a->map[i][b] == 'W' ||
			a->map[i][b] == 'S' || a->map[i][b] == 'E')
			{
				a->player->posx = b + 0.5;
				a->player->posy = i + 0.5;
				a->player->ch = a->map[i][b];
				playerstruct(a, a->map[i][b]);
			}
			b++;
		}
		i++;
	}
}
