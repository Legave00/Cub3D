#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

int				render_next_frame(t_bar *a)
{
	mlx_clear_window(a->mlx, a->win);
	cikl(a, a->player, a->ray);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	return (0);
}

int				ftclose(int keycode, t_bar *a)
{
	if (keycode == 13 || keycode == 1)
		movefb(keycode, a, a->player);
	if (keycode == 124 || keycode == 123)
		rotlr(keycode, a, a->player);
	if (keycode == 0 || keycode == 2)
		movelr(keycode, a, a->player);
	if (keycode == 53)
		exit(0);
	return (0);
}

void			text(t_bar *a)
{
	a->texx = (int)(a->wallx * (double)(a->texturka->width));
	if (a->ray->side == 0 && a->ray->raydirx > 0)
		a->texx = a->texturka->width - a->texx - 1;
	if (a->ray->side == 1 && a->ray->raydiry < 0)
		a->texx = a->texturka->width - a->texx - 1;
}

void			sidetex(t_bar *a, t_ray *ray, t_player *player)
{
	a->texturka = ft_calloc(1, sizeof(t_texturka));
	if (ray->side == 1)
	{
		a->texside = (player->posy < player->yp) ? 2 : 1;
		a->texturka->width = (a->texside == 1) ? a->tex->img_width_n : a->tex->img_width_so;
		a->texturka->hight = (a->texside == 1) ? a->tex->img_height_n : a->tex->img_height_so;
		a->texturka->addr = (a->texside == 1) ? a->tex->addrn : a->tex->addrso;
		a->texturka->ll = (a->texside == 1) ? a->tex->lln : a->tex->llso;
		a->texturka->bpp = (a->texside == 1) ? a->tex->bppn : a->tex->bppso;
	}
	else if (ray->side == 0)
	{
		a->texside = (player->posx < player->xp) ? 4 : 3;
		a->texturka->width = (a->texside == 3) ? a->tur->img_width_w : a->tur->img_width_e;
		a->texturka->hight = (a->texside == 3) ? a->tur->img_height_w : a->tur->img_height_e;
		a->texturka->addr = (a->texside == 3) ? a->tur->addrw : a->tur->addre;
		a->texturka->ll = (a->texside == 3) ? a->tur->llw : a->tur->lle;
		a->texturka->bpp = (a->texside == 3) ? a->tur->bppw : a->tur->bppe;
	}
}
void			textur(t_bar *a, t_tex *tex, t_tur *tur)
{
	tex->imgn = mlx_xpm_file_to_image(a->mlx, "./pics/bluestone.xpm", &tex->img_width_n, &tex->img_height_n);
	tur->imgw = mlx_xpm_file_to_image(a->mlx, "./pics/redbrick.xpm", &tur->img_width_w, &tur->img_height_w);
	tur->imge = mlx_xpm_file_to_image(a->mlx, "./pics/wood.xpm", &tur->img_width_e, &tur->img_height_e);
	tex->imgso = mlx_xpm_file_to_image(a->mlx, "./pics/mossy.xpm", &tex->img_width_so, &tex->img_height_so);
	tex->addrn = mlx_get_data_addr(tex->imgn, &tex->bppn, &tex->lln, &tex->endiann);
	tex->addrso = mlx_get_data_addr(tex->imgso, &tex->bppso, &tex->llso, &tex->endianso);
	tur->addrw = mlx_get_data_addr(tur->imgw, &tur->bppw, &tur->llw, &tur->endianw);
	tur->addre = mlx_get_data_addr(tur->imge, &tur->bppe, &tur->lle, &tur->endiane);
}

int				main(void)
{
	t_bar		*a = ft_calloc(1, sizeof(t_bar));

	a->player = ft_calloc(1, sizeof(t_player));
	a->ray  = ft_calloc(1, sizeof(t_ray));
	a->wall  = ft_calloc(1, sizeof(t_wall));
	reader(a);
	f1(a->map[0], a, 10, 0);
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, a->fir, a->sec, "cub");
	a->img = mlx_new_image(a->mlx, a->fir, a->sec);
	a->addr = mlx_get_data_addr(a->img, &a->bpp, &a->ll, &a->endian);
	textur(a, a->tex, a->tur);
	paint(search(a->map), a);
	mlx_hook(a->win, 2, 1L << 0, ftclose, a);
	mlx_loop_hook(a->mlx, render_next_frame, a);
	mlx_loop(a->mlx);
}