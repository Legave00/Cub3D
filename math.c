/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:21:12 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/21 21:48:02 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void	cikl(t_bar *a, t_player *player, t_ray *ray)
{
	while (a->x < a->fir)
	{
		player->camerax = 2 * a->x / (double)a->fir - 1;
		ray->raydirx = player->dirx + player->planex * a->player.camerax;
		ray->raydiry = player->diry + player->planey * a->player.camerax;
		delta(a, &a->player);
		a->x++;
	}
}
