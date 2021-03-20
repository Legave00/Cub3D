/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:35:44 by ydorene           #+#    #+#             */
/*   Updated: 2021/03/20 19:46:31 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void			mmpp(t_bar *a, int x, int y, int color)
{
	char	*dst;

	dst = a->addr + (y * a->ll + x * (a->bpp / 8));
	*(unsigned int*)dst = color;
}

float	mod(float a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

void	verline(int drawStart, int drawEnd, int color, t_bar *a)
{
	int i;

	i = 0;
	while (i <= drawStart)
	{
		mmpp(a, a->x, i, 0x0000A0F0);
		i++;
	}
	while (drawStart <= drawEnd)
	{
		if (a->ray->side == 1)
			mmpp(a, a->x, drawStart, color);
		else
			mmpp(a, a->x, drawStart, color / 2);
		drawStart++;
	}
	i = drawEnd;
	while (i <= a->sec)
	{
		mmpp(a, a->x, i, 0x00FF0000);
		i++;
	}
}

void	wall(t_bar *a, t_player *player, t_ray *ray)
{
	int		h;
	
	h = a->sec;
	if (ray->side == 0) 
		ray->perp = (a->player->xP - a->player->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
	else
		ray->perp = (a->player->yP - a->player->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
	a->wall->lineHight = (h / ray->perp);
	a->wall->drawStart = -a->wall->lineHight / 2 + h / 2;
	if (a->wall->drawStart < 0)
		a->wall->drawStart = 0;
	a->wall->drawEnd = a->wall->lineHight / 2 + h / 2;
	if (a->wall->drawEnd >= h)
		a->wall->drawEnd = h - 1;
	verline(a->wall->drawStart, a->wall->drawEnd, 0x00FFA07A, a);
}

void	runray(t_bar *a)
{
	a->player->xP = (int)a->player->posX;
	a->player->yP = (int)a->player->posY;
	a->ray->hit = 0;
	while (a->ray->hit == 0)
	{
		if (a->ray->sideDistX < a->ray->sideDistY)
		{
			a->ray->sideDistX += a->ray->deltaDistX;
			a->player->xP += a->ray->stepX;
			a->ray->side = 0;
		}
		else
		{
			a->ray->sideDistY += a->ray->deltaDistY;
			a->player->yP += a->ray->stepY;
			a->ray->side = 1;
		}
		if (a->map[a->player->yP][a->player->xP] == '1')
			a->ray->hit = 1;
	}
	wall(a, a->player, a->ray);
}

void		ray(t_bar *a)
{
	a->ray->deltaDistX = (a->ray->rayDirY == 0) ? 0 : ((a->ray->rayDirX == 0) ? 1 : mod(1 / a->ray->rayDirX));
	a->ray->deltaDistY = (a->ray->rayDirX == 0) ? 0 : ((a->ray->rayDirY == 0) ? 1 : mod(1 / a->ray->rayDirY));
	if (a->ray->rayDirX < 0)
	{
		a->ray->stepX = -1;
		a->ray->sideDistX = (a->player->posX - (int)a->player->posX) * a->ray->deltaDistX;
	}
	else
	{
		a->ray->stepX = 1;
		a->ray->sideDistX = ((int)a->player->posX + 1 - a->player->posX) * a->ray->deltaDistX;
	}
	if (a->ray->rayDirY < 0)
	{
		a->ray->stepY = -1;
		a->ray->sideDistY = (a->player->posY - (int)a->player->posY) * a->ray->deltaDistY;
	}
	else
	{
		a->ray->stepY = 1;
		a->ray->sideDistY = ((int)a->player->posY + 1 - a->player->posY) * a->ray->deltaDistY;
	}
	runray(a);
}

void		cikl(t_bar *a)
{
	a->x = 0;
	while (a->x < a->fir)
	{
		a->player->cameraX = 2 * a->x / (double)a->fir - 1;
		a->ray->rayDirX = a->player->dirX + a->player->planeX * a->player->cameraX;
		a->ray->rayDirY = a->player->dirY + a->player->planeY * a->player->cameraX;
		ray(a);
		a->x++;
	}
}

void		playerstruct(t_bar *a, char pla)
{
	a->x = 0;
	if (pla == 'N' || pla == 'S')
	{
		a->player->dirX = 0;
		a->player->dirY = ((pla == 'N') ? -1 : 1);
		a->player->planeX = ((pla == 'N') ? 0.66 : -0.66);
		a->player->planeY = 0;
	}
	else
	{
		a->player->dirX = ((pla == 'W') ? -1 : 1);
		a->player->dirY = 0;
		a->player->planeY = ((pla == 'W') ? -0.66 : 0.66);
		a->player->planeX = 0;
	}
}

void	paint(int i, t_bar *a)
{
	int	b;
	b = 0;
	while (a->map[i])
	{
		b = 0;
		while (a->map[i][b])
		{
			if (a->map[i][b] == 'N'|| a->map[i][b] == 'W' || a->map[i][b] == 'S' || a->map[i][b] == 'E')
			{
				a->player->posX = b + 0.5;
				a->player->posY = i + 0.5;
				a->player->ch = a->map[i][b];
				playerstruct(a, a->map[i][b]);
			}
			b++;
		}
		i++;
	}
}

int	 render_next_frame(t_bar *a)
{
	mlx_clear_window (a->mlx, a->win);
	cikl(a);
	mlx_put_image_to_window (a->mlx, a->win, a->img, 0, 0);
	return (0);
}

void		movefb(int keycode, t_bar *a)
{
	if (keycode == 13)
	{
		if (a->map[(int)(a->player->posY + a->player->dirY)][(int)a->player->posX] == '0' ||
		a->map[(int)(a->player->posY + a->player->dirY)][(int)a->player->posX] == a->player->ch)
			a->player->posY += a->player->dirY;
		if (a->map[(int)a->player->posY][(int)(a->player->posX + a->player->dirX)] == '0' ||
		a->map[(int)a->player->posY][(int)(a->player->posX + a->player->dirX)] == a->player->ch)
			a->player->posX += a->player->dirX;
	}
	if (keycode == 1)
	{
		if (a->map[(int)(a->player->posY - a->player->dirY)][(int)a->player->posX] == '0' ||
		a->map[(int)(a->player->posY - a->player->dirY)][(int)a->player->posX] == a->player->ch)
			a->player->posY -= a->player->dirY;
		if (a->map[(int)a->player->posY][(int)(a->player->posX - a->player->dirX)] == '0' ||
		a->map[(int)a->player->posY][(int)(a->player->posX - a->player->dirX)] == a->player->ch)
			a->player->posX -= a->player->dirX;
	}
}

void		rotlr(int keycode, t_bar *a)
{
	float tmp;

	tmp = (keycode == 123) ? -0.09 : (keycode == 124) ? 0.09 : 0;
	a->player->oldPlaneX = a->player->planeX;
	a->player->oldDirX = a->player->dirX;
	a->player->dirX = a->player->dirX * cos(tmp) - a->player->dirY * sin(tmp);
    a->player->dirY = a->player->oldDirX * sin(tmp) + a->player->dirY * cos(tmp);
	a->player->planeX = a->player->planeX * cos(tmp) - a->player->planeY * sin(tmp);
    a->player->planeY = a->player->oldPlaneX * sin(tmp) + a->player->planeY * cos(tmp);
}

void		movelr(int keycode, t_bar *a)
{
	if (keycode == 2)
	{
		if (a->map[(int)(a->player->posY + a->player->planeY)][(int)a->player->posX] == '0' ||
		a->map[(int)(a->player->posY + a->player->planeY)][(int)a->player->posX] == a->player->ch)
			a->player->posY += a->player->planeY;
		if (a->map[(int)a->player->posY][(int)(a->player->posX + a->player->planeX)] == '0' ||
		a->map[(int)a->player->posY][(int)(a->player->posX + a->player->planeX)] == a->player->ch)
			a->player->posX += a->player->planeX;
	}
	if (keycode == 0)
	{
		if (a->map[(int)(a->player->posY - a->player->planeY)][(int)a->player->posX] == '0' ||
		a->map[(int)(a->player->posY - a->player->planeY)][(int)a->player->posX] == a->player->ch)
			a->player->posY -= a->player->planeY;
		if (a->map[(int)a->player->posY][(int)(a->player->posX - a->player->planeX)] == '0' ||
		a->map[(int)a->player->posY][(int)(a->player->posX - a->player->planeX)] == a->player->ch)
			a->player->posX -= a->player->planeX;
	}
}

int			 ftclose(int keycode, t_bar *a)
{
	if (keycode == 13 || keycode == 1)
		movefb(keycode, a);
	if (keycode == 124 || keycode == 123)
		rotlr(keycode, a);
	if (keycode == 0 || keycode == 2)
		movelr(keycode, a);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	 main(void)
{
	int			fd;
	int			i;
	char		*line = NULL;
	t_list  	*head;
	t_bar 		a;
	t_player	p;
	t_ray		r;
	t_wall		w;

	a.player = &p;
	a.ray = &r;
	a.wall = &w;
	fd = open("a", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	a.map = readbuf(&head, ft_lstsize(head), &a);
	f1(a.map[0], &a);
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, a.fir, a.sec, "cub");
	a.img = mlx_new_image(a.mlx, a.fir, a.sec);
	a.addr = mlx_get_data_addr(a.img, &a.bpp, &a.ll, &a.endian);
	paint(search(a.map), &a);
	mlx_hook(a.win, 2, 1L<<0, ftclose, &a);
	mlx_loop_hook(a.mlx, render_next_frame, &a);
	mlx_loop(a.mlx);
}