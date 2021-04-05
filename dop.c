/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:49:51 by ydorene           #+#    #+#             */
/*   Updated: 2021/03/26 04:04:52 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void			defstruct(t_bar *a)
{
	a->tex  = ft_calloc(1, sizeof(t_tex));
	a->tur  = ft_calloc(1, sizeof(t_tur));
	a->fir = 0;
	a->sec = 0;
	a->ll = 0;
	a->bpp = 0;
	a->endian = 0;
	a->mlx = NULL;
	a->win = NULL;
	a->img = NULL;
	a->addr = NULL;
	a->player->posx = 0;
	a->player->posy = 0;
	a->player->xp = 0;
	a->player->yp = 0;
	a->ray->hit = 0;
}

void			againstr(t_bar *a)
{
	a->tex->img_height_n = 0;
	a->tex->img_height_so = 0;
	a->tur->img_height_e = 0;
	a->tur->img_height_w = 0;
	a->tur->img_width_e = 0;
	a->tur->img_width_w = 0;
	a->tex->img_width_n = 0;
	a->tex->img_width_so = 0;
	// a->texturka->addr = NULL;
	a->tex->addrn = NULL;
	a->tex->addrso = NULL;
	a->tur->addrw = NULL;
	a->tur->addre = NULL;
}

void			f1(char *line, t_bar *a, int i, int num)
{
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
				break ;
			}
		}
		line++;
	}
}

void			readbuf(t_list **head, int size, t_bar *a)
{
	char	**map;
	int		y;
	t_list	*tmp;

	tmp = *head;
	map = malloc((size + 1) * sizeof(char*));
	y = -1;
	while (tmp)
	{
		map[++y] = tmp->content;
		tmp = tmp->next;
	}
	y = search(map) - 1;
	while (map[++y])
		ft_putendl_fd(map[y], 1);
	a->map = map;
}

int				search(char **map)
{
	int i;

	i = 1;
	while (map[i - 1][0] != 'C')
		i++;
	while (map[i][0] == '\0')
		i++;
	return (i);
}

void			reader(t_bar *a)
{
	int		fd;
	char	*line;
	int		i;
	t_list	*head;

	line = NULL;
	head  = NULL;
	fd = open("a", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	readbuf(&head, ft_lstsize(head), a);
}
