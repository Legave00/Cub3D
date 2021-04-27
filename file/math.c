/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:21:12 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 07:02:01 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	cikl(t_bar *a, t_player *player, t_ray *ray)
{
	while (a->x < a->w)
	{
		player->camerax = 2 * a->x / (double)a->w - 1;
		ray->raydirx = player->dirx + player->planex * a->player.camerax;
		ray->raydiry = player->diry + player->planey * a->player.camerax;
		delta(a);
		a->x++;
	}
}
