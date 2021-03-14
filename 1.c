/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   1.c												:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ydorene <ydorene@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/03/02 21:05:25 by ydorene		   #+#	#+#			 */
/*   Updated: 2021/03/08 21:12:48 by ydorene		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void		defstruct(t_list2 *a)
{
	a->fir = 0;
	a->sec = 0;
	a->ll = 0;
	a->bpp = 0;
	a->endian = 0;
	a->mlx = NULL;
	a->win = NULL;
	a->img = NULL;
	a->addr = NULL;
	a->player.posX = 0;
	a->player.posY = 0;
	a->player.xP = 0;
	a->player.yP = 0;
}

void		playerstruct(t_player player, char pla)
{
	if (pla == 'N' || pla == 'S')
	{
		player.dirX = 0;
		player.dirY = ((pla == 'N') ? -1 : 1);
	}
	else

}

void		f1(char *line, t_list2 *a)
{
	int	 num = 0;
	int	 i = 10;

	defstruct(a);
	while (line)
	{
		if (*line > 48 && *line <= 57)
		{
			while (*line >= 48 && *line <= 57)
			{
				num = num * i + (*line - 48);
				line++;
			}
			if (a->fir == 0)
			{
				a->fir = num;
				num = 0;
			}
			else
			{
				a->sec = num;
				break;
			}
		}
		line++;
	}
}

char	**readbuf(t_list **head, int size)
{
	char	**map = malloc((size + 1) * sizeof(char*));
	int x = -1;
	int y = -1;

	t_list  *tmp = *head;

	while (tmp)
	{
		map[++y] = tmp->content;
		tmp = tmp->next;
	}
	y = -1;
	while (map[++y])
		ft_putendl_fd(map[y] ,1);
	return (map);
}

int	 search(char **map)
{
	int i = 1;

	while (map[i - 1][0] != 'C')
		i++;
	while (map[i][0] == '\0')
		i++;
	return (i);
}

void			mmpp(t_list2 *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void			my_mlx_pixel_put(int color, t_list2 *data, float x, float y, int scale)
{
	int z;
	int	c;


	z = (x + 1) * scale;
	c = (y + 1) * scale;
	x *= scale;
	y *= scale;
	while (y <= c)
	{
		while (x <= z)
		{
			mmpp(data, x, y, color);
			x++;
		}
		x = (z / scale - 1) * scale;
		y++;
	}
}

void	paint(int i, t_list2 *a)
{
	int	b;

	b = 0;
	while (a->map[i])
	{
		b = 0;
		while (a->map[i][b])
		{
			if (a->map[i][b] == '1' || a->map[i][b] == '2')
				my_mlx_pixel_put(0x00FF0000, a, b, i, 16);
			if (a->map[i][b] == 'N'|| a->map[i][b] == 'W' || a->map[i][b] == 'S' || a->map[i][b] == 'E')
			{
				playerstruct(a->player, a->map[i][b]);
				a->player.posX = b;
				a->player.posY = i;
			}
			b++;
		}
		i++;
	}
}

int			 key_hook(int keycode, t_list2 *a)
{
	if (keycode == 13)
	{
		a->player.xP = a->player.posX;
		a->player.yP = a->player.posY;
		if (a->map[a->player.yP - 1][a->player.xP] == '0')
		{
			my_mlx_pixel_put(0x00000000, a, a->player.posX, a->player.posY, 16);
			a->player.posY -= 1;
		}
	}
	return (0);
}

int	 render_next_frame(t_list2 *a)
{
	my_mlx_pixel_put(0x0000FF00, a, a->player.posX, a->player.posY, 16);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	return (0);
}

int	 main(void)
{
	int		fd;
	int		i;
	char	*line = NULL;
	t_list  *head;
	t_list2 *a;
	t_list2 b;

	a = &b;
	fd = open("a", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	a->map = readbuf(&head, ft_lstsize(head));
	f1(a->map[0], a);
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, a->fir, a->sec, "cub");
	a->img = mlx_new_image(a->mlx, a->fir, a->sec);
	a->addr = mlx_get_data_addr(a->img, &a->bpp, &a->ll, &a->endian);
	paint(search(a->map), a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_key_hook(a->win, key_hook, a);
	mlx_loop_hook(a->mlx, render_next_frame, a);
	mlx_loop(a->mlx);
}