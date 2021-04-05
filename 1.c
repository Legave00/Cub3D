int				main(void)
{
	t_bar		*a = ft_calloc(1, sizeof(t_bar));
	t_player	p;
	t_ray		r;
	t_wall		w;

	a->player = &p;
	a->ray = &r;
	a->wall = &w;
	reader(&a);
	f1(a->map[0], &a, 10, 0);
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, a->fir, a->sec, "cub");
	a->img = mlx_new_image(a->mlx, a->fir, a->sec);
	a->addr = mlx_get_data_addr(a->img, &a->bpp, &a->ll, &a->endian);
	textur(&a, a->tex, a->tur);
	paint(search(a->map), &a);
	mlx_hook(a->win, 2, 1L << 0, ftclose, &a);
	mlx_loop_hook(a->mlx, render_next_frame, &a);
	mlx_loop(a->mlx);
}