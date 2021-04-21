/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:53:29 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/21 23:27:55 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void	casting(int fd, t_bar *a)
{
	reader(a, fd);
	f1(a->map[0], a, 10, 0);
	a->win.mlx = mlx_init();
	a->win.win = mlx_new_window(a->win.mlx, a->fir, a->sec, "cub");
	a->win.img = mlx_new_image(a->win.mlx, a->fir, a->sec);
	a->win.addr = mlx_get_data_addr(a->win.img, &a->win.bpp,
			&a->win.ll, &a->win.endian);
	textur(a, &a->tex, &a->tur);
	paint(search(a->map), a, &a->player);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_bar	a;

	if (argc > 1)
	{
		fd = open("a", O_RDONLY);
		if (argv[2] && !ft_strncmp(argv[2], "--save", 6))
			scsh(fd, &a);
		else
			casting(fd, &a);
	}
	else
	{
		printf("Error\nпашел на хуй\n");
		exit(0);
	}
	mlx_hook(a.win.win, 2, 1L << 0, ftclose, &a);
	mlx_hook(a.win.win, 17, 0, ftclose2, &a);
	mlx_loop_hook(a.win.mlx, render_next_frame, &a);
	mlx_loop(a.win.mlx);
}
