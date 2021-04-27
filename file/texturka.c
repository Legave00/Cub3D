/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturka.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:50:59 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 07:19:42 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	sidetex(t_bar *a, t_player *player)
{
	if (a->ray.side == 1)
	{
		if (player->posy < player->yp)
			a->texside = 2;
		else
			a->texside = 1;
		if (a->texside == 1)
			n(a, &a->tex);
		else
			so(a, &a->tex);
	}
	else if (a->ray.side == 0)
	{
		if (player->posx < player->xp)
			a->texside = 4;
		else
			a->texside = 3;
		if (a->texside == 3)
			w(a, &a->tur);
		else
			e(a, & a->tur);
	}
}

void	n(t_bar *a, t_tex *tex)
{
	a->texturka.width = tex->iw_n;
	a->texturka.hight = tex->ih_n;
	a->texturka.addr = tex->addrn;
	a->texturka.ll = tex->lln;
	a->texturka.bpp = tex->bppn;
}

void	so(t_bar *a, t_tex *tex)
{
	a->texturka.width = tex->iw_so;
	a->texturka.hight = tex->ih_so;
	a->texturka.addr = tex->addrso;
	a->texturka.ll = tex->llso;
	a->texturka.bpp = tex->bppso;
}

void	w(t_bar *a, t_tur *tur)
{
	a->texturka.width = tur->iw_w;
	a->texturka.hight = tur->ih_w;
	a->texturka.addr = tur->addrw;
	a->texturka.ll = tur->llw;
	a->texturka.bpp = tur->bppw;
}

void	e(t_bar *a, t_tur *tur)
{
	a->texturka.width = tur->iw_e;
	a->texturka.hight = tur->ih_e;
	a->texturka.addr = tur->addre;
	a->texturka.ll = tur->lle;
	a->texturka.bpp = tur->bppe;
}
