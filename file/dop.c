/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:49:51 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 06:58:17 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	defstruct(t_bar *a)
{
	a->w = -1;
	a->h = -1;
	a->win.ll = 0;
	a->win.bpp = 0;
	a->win.endian = 0;
	a->player.posx = 0;
	a->player.posy = 0;
	a->player.xp = 0;
	a->player.yp = 0;
	a->ray.hit = 0;
	a->x = 0;
	a->kolspr = 0;
	a->wall.floor = -1;
	a->wall.ceiling = -1;
	a->way.ea = NULL;
	a->way.we = NULL;
	a->way.no = NULL;
	a->way.s = NULL;
	a->way.so = NULL;
	a->wall.linest = -1;
	a->wall.linemap = -1;
}

void	drstruct(t_drawsp *dr)
{
	dr->dex = 0;
	dr->dey = 0;
	dr->dsx = 0;
	dr->dsy = 0;
	dr->invdet = 0;
	dr->sph = 0;
	dr->spw = 0;
	dr->ssx = 0;
	dr->spritex = 0;
	dr->spritey = 0;
	dr->transy = 0;
	dr->transx = 0;
	dr->texy = 0;
	dr->texx = 0;
	dr->d = 0;
	dr->c = 0;
	dr->color = 0;
}

void	readbuf(t_list **head, int size, t_bar *a)
{
	int		y;
	t_list	*tmp;

	tmp = *head;
	a->size = size;
	a->map = malloc((size + 1) * sizeof(char *));
	ifn(a->map);
	y = -1;
	while (tmp)
	{
		a->map[++y] = tmp->content;
		tmp = tmp->next;
	}
	a->map[size] = NULL;
	y = -1;
	while (++y < size)
		ft_putendl_fd(a->map[y], 1);
}

void	reader(t_bar *a, int fd)
{
	char	*line;
	t_list	*tmp;
	t_list	*head;

	line = NULL;
	head = NULL;
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	readbuf(&head, ft_lstsize(head), a);
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

int	sum(char **line, t_bar *a, int i, double num)
{
	int	z;

	z = 0;
	while (**line >= 48 && **line <= 57)
	{
		num = num * i + (**line - 48);
		(*line)++;
		z++;
	}
	if (z > 4 && a->w == -1)
		num = 2560;
	else if (z > 4)
		num = 1440;
	return (num);
}
