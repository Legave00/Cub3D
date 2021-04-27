/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:19:24 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 07:22:49 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	movefb(int keycode, t_bar *a, t_player *player)
{
	if (keycode == 13)
	{
		if (a->map[(int)(player->posy
				+ player->diry)][(int)player->posx] == '0' ||
				a->map[(int)(player->posy
				+ player->diry)][(int)player->posx] == player->ch)
			player->posy += player->diry;
		if (a->map[(int)player->posy][(int)(player->posx
			+ player->dirx)] == '0' ||
			a->map[(int)player->posy][(int)(player->posx
			+ player->dirx)] == player->ch)
			player->posx += player->dirx;
	}
	if (keycode == 1)
	{
		if (a->map[(int)(player->posy
				- player->diry)][(int)player->posx] == '0' ||
				a->map[(int)(player->posy
				- player->diry)][(int)player->posx] == player->ch)
			player->posy -= player->diry;
		if (a->map[(int)player->posy][(int)(player->posx
			- player->dirx)] == '0' || a->map[(int)player->posy]
			[(int)(player->posx - player->dirx)] == player->ch)
			player->posx -= player->dirx;
	}
}

void	rotlr(int keycode, t_player *player)
{
	float	tmp;

	if (keycode == 123)
		tmp = -0.09;
	else
		tmp = 0.09;
	player->oldplanex = player->planex;
	player->olddirx = player->dirx;
	player->dirx = player->dirx * cos(tmp) - player->diry * sin(tmp);
	player->diry = player->olddirx * sin(tmp) + player->diry * cos(tmp);
	player->planex = player->planex * cos(tmp) - player->planey * sin(tmp);
	player->planey = player->oldplanex * sin(tmp) + player->planey * cos(tmp);
}

void	movelr(int keycode, t_bar *a, t_player *player)
{
	if (keycode == 2)
	{
		if (a->map[(int)(player->posy
				+ player->planey)][(int)player->posx] == '0' ||
				a->map[(int)(player->posy
				+ player->planey)][(int)player->posx] == player->ch)
			player->posy += player->planey;
		if (a->map[(int)player->posy][(int)(player->posx
			+ player->planex)] == '0' ||
			a->map[(int)player->posy][(int)(player->posx
			+ player->planex)] == player->ch)
			player->posx += player->planex;
	}
	if (keycode == 0)
	{
		if (a->map[(int)(player->posy
				- player->planey)][(int)player->posx] == '0' ||
				a->map[(int)(player->posy
				- player->planey)][(int)player->posx] == player->ch)
			player->posy -= player->planey;
		if (a->map[(int)player->posy][(int)(player->posx
			- player->planex)] == '0' || a->map[(int)player->posy]
			[(int)(player->posx - player->planex)] == player->ch)
			player->posx -= player->planex;
	}
}

int	checkparams(t_bar *a)
{
	if (a->way.s != NULL && a->way.so != NULL
		&& a->way.we != NULL && a->way.ea != NULL
		&& a->way.no != NULL && a->wall.floor != -1
		&& a->wall.ceiling != -1)
		return (1);
	else
		return (0);
}

void	textcheck(t_bar *a, int i, int j, t_wall *wall)
{
	while (++i < a->size && a->map[i])
	{
		j = 0;
		if (ft_strchrsec("NSWE", a->map[i][0]))
			textcheck2(a->map[i], &a->way);
		else if (ft_strchrsec("FC", a->map[i][0]))
			checkfloor(a->map[i], &a->wall);
		else if (checkparams(a))
		{
			wall->linest = i;
			longestline(a);
			break ;
		}
	}
	if (a->way.s == NULL || a->way.so == NULL
		|| a->way.we == NULL || a->way.ea == NULL || a->way.no == NULL)
		printerror("не хвататет текстур");
	if (a->wall.floor == -1 || a->wall.ceiling == -1)
		printerror("нет настроек для пола или потолка");
	checktrash(a, &a->wall);
}
