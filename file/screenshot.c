/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:53:10 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 07:04:42 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	screenshot2(int fd, t_bar *a)
{
	int32_t	x;
	int32_t	y;
	int		color;

	y = a->h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < a->w)
		{
			color = *(unsigned int *)(a->win.addr
					+ (y * a->win.ll + x * (a->win.bpp / 8)));
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
	close(fd);
	exit(0);
}

void	screenshot(t_bar *a)
{
	int		fd;
	char	bitmap[54];

	fd = 0;
	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		printf("Error\nСreating a screenshot resulted in an error");
		exit(-1);
	}
	ft_bzero(bitmap, 54);
	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int *)(bitmap + 2)) = a->h
		* a->w * 4 + 54;
	*(int *)(bitmap + 10) = 54;
	*(int *)(bitmap + 14) = 40;
	*(int *)(bitmap + 18) = a->w;
	*(int *)(bitmap + 22) = a->h;
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	write(fd, bitmap, 54);
	screenshot2(fd, a);
}

int	render_next_frame(t_bar *a)
{
	int	*m;

	mlx_clear_window(a->win.mlx, a->win.win);
	cikl(a, &a->player, &a->ray);
	a->x = 0;
	m = spdist(a, a->kolspr);
	drawspr(a, &a->player, &a->dr, &a->texturka);
	free (m);
	mlx_put_image_to_window(a->win.mlx, a->win.win, a->win.img, 0, 0);
	return (0);
}

int	ftclose(int keycode, t_bar *a)
{
	if (keycode == 13 || keycode == 1)
		movefb(keycode, a, &a->player);
	if (keycode == 0 || keycode == 2)
		movelr(keycode, a, &a->player);
	if (keycode == 124 || keycode == 123)
		rotlr(keycode, &a->player);
	if (keycode == 53)
	{
		freeall(a, &a->player);
		exit(0);
	}
	return (0);
}

int	ftclose2(t_bar *a)
{
	freeall(a, &a->player);
	exit(0);
}
