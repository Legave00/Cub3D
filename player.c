/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:24:05 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/20 18:56:58 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void	playerstruct(t_bar *a, char pla)
{
	if (pla == 'N' || pla == 'S')
	{
		if (pla == 'N')
			pn(a);
		else
			pso(a);
	}
	else
	{
		if (pla == 'W')
			pw(a);
		else
			pe(a);
	}
}

void	pn(t_bar *a)
{
	a->player.dirx = 0;
	a->player.diry = -1;
	a->player.planex = 0.66;
	a->player.planey = 0;
}

void	pso(t_bar *a)
{
	a->player.dirx = 0;
	a->player.diry = 1;
	a->player.planex = -0.66;
	a->player.planey = 0;
}

void	pw(t_bar *a)
{
	a->player.dirx = -1;
	a->player.diry = 0;
	a->player.planey = -0.66;
	a->player.planex = 0;
}

void	pe(t_bar *a)
{
	a->player.dirx = 1;
	a->player.diry = 0;
	a->player.planey = 0.66;
	a->player.planex = 0;
}
