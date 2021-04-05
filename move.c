/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:19:24 by ydorene           #+#    #+#             */
/*   Updated: 2021/03/23 17:20:22 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void			movefb(int keycode, t_bar *a, t_player *player)
{
	if (keycode == 13)
	{
		if (a->map[(int)(player->posy +
		player->diry)][(int)player->posx] == '0' ||
		a->map[(int)(player->posy +
		player->diry)][(int)player->posx] == player->ch)
			player->posy += player->diry;
		if (a->map[(int)player->posy][(int)(player->posx +
		player->dirx)] == '0' ||
		a->map[(int)player->posy][(int)(player->posx +
		player->dirx)] == player->ch)
			player->posx += player->dirx;
	}
	if (keycode == 1)
	{
		if (a->map[(int)(player->posy -
		player->diry)][(int)player->posx] == '0' ||
		a->map[(int)(player->posy -
		player->diry)][(int)player->posx] == player->ch)
			player->posy -= player->diry;
		if (a->map[(int)player->posy][(int)(player->posx -
		player->dirx)] == '0' || a->map[(int)player->posy]
		[(int)(player->posx - player->dirx)] == player->ch)
			player->posx -= player->dirx;
	}
}

void			rotlr(int keycode, t_bar *a, t_player *player)
{
	float tmp;

	tmp = (keycode == 123) ? -0.09 : 0.09;
	player->oldplanex = player->planex;
	player->olddirx = player->dirx;
	player->dirx = player->dirx * cos(tmp) - player->diry * sin(tmp);
	player->diry = player->olddirx * sin(tmp) + player->diry * cos(tmp);
	player->planex = player->planex * cos(tmp) - player->planey * sin(tmp);
	player->planey = player->oldplanex * sin(tmp) + player->planey * cos(tmp);
}

void			movelr(int keycode, t_bar *a, t_player *player)
{
	if (keycode == 2)
	{
		if (a->map[(int)(player->posy +
		player->planey)][(int)player->posx] == '0' ||
		a->map[(int)(player->posy +
		player->planey)][(int)player->posx] == player->ch)
			player->posy += player->planey;
		if (a->map[(int)player->posy][(int)(player->posx +
		player->planex)] == '0' ||
		a->map[(int)player->posy][(int)(player->posx +
		player->planex)] == player->ch)
			player->posx += player->planex;
	}
	if (keycode == 0)
	{
		if (a->map[(int)(player->posy -
		player->planey)][(int)player->posx] == '0' ||
		a->map[(int)(player->posy -
		player->planey)][(int)player->posx] == player->ch)
			player->posy -= player->planey;
		if (a->map[(int)player->posy][(int)(player->posx -
		player->planex)] == '0' || a->map[(int)player->posy]
		[(int)(player->posx - player->planex)] == player->ch)
			player->posx -= player->planex;
	}
}

