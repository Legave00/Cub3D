/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:53:29 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 09:45:42 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX1/mlx.h"
#include "cub.h"
#include "libft/libft.h"

void	casting(t_bar *a)
{
	a->win.mlx = mlx_init();
	a->win.win = mlx_new_window(a->win.mlx, a->w, a->h, "cub");
	a->win.img = mlx_new_image(a->win.mlx, a->w, a->h);
	a->win.addr = mlx_get_data_addr(a->win.img, &a->win.bpp,
			&a->win.ll, &a->win.endian);
	textur(a, &a->tex, &a->tur, &a->way);
	paint(a->wall.linest, a, &a->player, 0);
}

int	readcheck(char *s, int fd)
{
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printerror("ошибка файла\n");
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_bar	a;

	fd = 0;
	if (argc > 1 && argc < 4)
	{
		fd = readcheck(argv[1], fd);
		parser(&a, fd, argv[1]);
		if (argc == 3 && argv[2])
		{
			if ((ft_strlen(argv[2]) == 6) && !ft_strncmp(argv[2], "--save", 6))
				scsh(&a);
			else
				printerror("неправильные аргументы");
		}
		else if (argc == 2)
			casting(&a);
	}
	else
		printerror("неправильные аргументы");
	mlx_hook(a.win.win, 2, 1L << 0, ftclose, &a);
	mlx_hook(a.win.win, 17, 0, ftclose2, &a);
	mlx_loop_hook(a.win.mlx, render_next_frame, &a);
	mlx_loop(a.win.mlx);
}
