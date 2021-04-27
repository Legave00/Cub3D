/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   drawsprite.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ydorene <ydorene@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/04/21 22:57:31 by ydorene		   #+#	#+#			 */
/*   Updated: 2021/04/21 23:08:35 by ydorene		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	cidraw(t_bar *a, t_drawsp *dr, t_texturka *texturka)
{
	int	j;

	j = dr->dsx - 1;
	while (++j < dr->dex)
	{
		dr->texx = (int)(256 * (j - (-dr->spw / 2 + dr->ssx))
				* texturka->width / dr->spw) / 256;
		if (dr->transy > 0 && j > 0 && j < a->w
			&& dr->transy < a->player.perpmass[j])
		{
			dr->c = dr->dsy - 1;
			while (++dr->c < dr->dey)
			{
				dr->d = dr->c * 256 - a->h * 128 + dr->sph * 128;
				dr->texy = ((dr->d * texturka->hight) / dr->sph) / 256;
				dr->color = *(unsigned int *)(a->sp.addrsp
						+ (dr->texy * a->sp.llsp + dr->texx
							* (a->sp.bppsp / 8)));
				if (dr->color != 0x00000000)
					mmpp(a, j, dr->c, dr->color);
			}
		}
	}
}

void	initdraw(int i, t_bar *a, t_player *player, t_drawsp *dr)
{
	dr->spritex = a->sprite[a->texturka.massdist[i]].x - player->posx;
	dr->spritey = a->sprite[a->texturka.massdist[i]].y - player->posy;
	dr->invdet = 1.0 / (player->planex * player->diry
			- player->dirx * player->planey);
	dr->transx = dr->invdet * (player->diry * dr->spritex
			- player->dirx * dr->spritey);
	dr->transy = dr->invdet * (-player->planey * dr->spritex
			+ player->planex * dr->spritey);
	dr->ssx = (int)((a->w / 2) * (1 + dr->transx / dr->transy));
	dr->sph = abs((int)(a->h / dr->transy))
		* ((double)a->w / (double)a->h);
	dr->spw = abs((int)(a->h / dr->transy))
		* ((double)a->w / (double)a->h);
	dr->dsy = -dr->sph / 2 + a->h / 2;
}

void	drawspr(t_bar *a, t_player *player, t_drawsp *dr, t_texturka *texturka)
{
	int		i;

	i = -1;
	drstruct(dr);
	while (++i < a->kolspr)
	{
		initdraw(i, a, player, dr);
		if (dr->dsy < 0)
			dr->dsy = 0;
		dr->dey = dr->sph / 2 + a->h / 2;
		if (dr->dey >= a->h)
			dr->dey = a->h -1;
		dr->dsx = -dr->spw / 2 + dr->ssx;
		if (dr->dsx < 0)
			dr->dsx = 0;
		dr->dex = dr->spw / 2 + dr->ssx;
		if (dr->dex >= a->w)
			dr->dex = a->w -1;
		cidraw(a, dr, texturka);
	}
}

char	*ft_strchrsec(const char *str, int ch)
{
	char	*a;

	a = (char *)str;
	while (*a != '\0')
	{
		if (*a == ch)
			return (a);
		a++;
	}
	return (0);
}

void	checktrash(t_bar *a, t_wall *wall)
{
	int	i;
	int	j;

	i = 0;
	if (wall->linemap == a->size || wall->linest == -1)
		printerror("нет карты");
	while (++i < wall->linest)
	{
		if (a->map[i][0] != '\0' && !ft_strchrsec("NSWE", a->map[i][0])
			&& !ft_strchrsec("FC", a->map[i][0]))
			printerror("мусор");
	}
	i = wall->linest - 1;
	while (++i < a->size)
	{
		j = -1;
		while (a->map[i][++j])
		{
			if (!ft_strchr(" \t012NSWE", a->map[i][j]))
				printerror("мусор");
		}
	}
}
