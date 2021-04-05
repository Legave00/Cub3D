#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void			cikl(t_bar *a, t_player *player, t_ray *ray)
{
	a->x = 0;
	while (a->x < a->fir)
	{
		player->camerax = 2 * a->x / (double)a->fir - 1;
		ray->raydirx = player->dirx + player->planex * a->player->camerax;
		ray->raydiry = player->diry + player->planey * a->player->camerax;
		delta(a, a->player);
		a->x++;
	}
}

void			playerstruct(t_bar *a, char pla)
{
	a->x = 0;
	if (pla == 'N' || pla == 'S')
	{
		a->player->dirx = 0;
		a->player->diry = ((pla == 'N') ? -1 : 1);
		a->player->planex = ((pla == 'N') ? 0.66 : -0.66);
		a->player->planey = 0;
	}
	else
	{
		a->player->dirx = ((pla == 'W') ? -1 : 1);
		a->player->diry = 0;
		a->player->planey = ((pla == 'W') ? -0.66 : 0.66);
		a->player->planex = 0;
	}
}