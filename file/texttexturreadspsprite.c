/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texttexturreadspsprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:35:35 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 10:02:46 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	text(t_bar *a)
{
	a->texx = (int)(a->wallx * (double)(a->texturka.width));
	if (a->ray.side == 0 && a->ray.raydirx > 0)
		a->texx = a->texturka.width - a->texx - 1;
	if (a->ray.side == 1 && a->ray.raydiry < 0)
		a->texx = a->texturka.width - a->texx - 1;
}

void	textur(t_bar *a, t_tex *tex, t_tur *tur, t_way *way)
{
	tex->imgn = mlx_xpm_file_to_image(a->win.mlx, way->no,
			&tex->iw_n, &tex->ih_n);
	tur->imgw = mlx_xpm_file_to_image(a->win.mlx, way->we,
			&tur->iw_w, &tur->ih_w);
	tur->imge = mlx_xpm_file_to_image(a->win.mlx, way->ea,
			&tur->iw_e, &tur->ih_e);
	tex->imgso = mlx_xpm_file_to_image(a->win.mlx, way->so,
			&tex->iw_so, &tex->ih_so);
	checkway(tex, tur);
	tex->addrn = mlx_get_data_addr(tex->imgn,
			&tex->bppn, &tex->lln, &tex->endiann);
	tex->addrso = mlx_get_data_addr(tex->imgso,
			&tex->bppso, &tex->llso, &tex->endianso);
	tur->addrw = mlx_get_data_addr(tur->imgw,
			&tur->bppw, &tur->llw, &tur->endianw);
	tur->addre = mlx_get_data_addr(tur->imge,
			&tur->bppe, &tur->lle, &tur->endiane);
	readsprite(a, &a->sp, way);
}

void	readsprite(t_bar *a, t_readsp *sp, t_way *way)
{
	sp->imgsp = mlx_xpm_file_to_image(a->win.mlx, way->s,
			&sp->iw_sp, &sp->ih_sp);
	if (!sp->imgsp)
		printerror("невалидный путь");
	sp->addrsp = mlx_get_data_addr(sp->imgsp,
			&sp->bppsp, &sp->llsp, &sp->endiansp);
}

int	*spdist(t_bar *a, int r)
{
	int		i;

	i = 0;
	a->texturka.massdist = malloc(r * sizeof(int));
	ifn(a->texturka.massdist);
	while (i < r)
	{
		a->texturka.massdist[i] = ((int)a->player.posy - a->sprite[i].y)
			* ((int)a->player.posy - a->sprite[i].y)
			+ ((int)a->player.posx - a->sprite[i].x)
			* ((int)a->player.posx - a->sprite[i].x);
		i++;
	}
	return (sort(a->texturka.massdist, a));
}

void	sprite(t_bar *a)
{
	int			i;
	int			r;
	int			j;

	i = a->wall.linest - 1;
	r = -1;
	a->sprite = malloc(a->kolspr * sizeof(t_sprite));
	ifn(a->sprite);
	while (a->map[++i])
	{
		j = -1;
		while (a->map[i][++j])
		{
			if (a->map[i][j] == '2')
			{
				a->sprite[++r].y = i + 0.5;
				a->sprite[r].x = j + 0.5;
			}
		}
	}
}
