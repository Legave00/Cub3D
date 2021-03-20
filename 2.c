/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:49:51 by ydorene           #+#    #+#             */
/*   Updated: 2021/03/20 19:27:32 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void		defstruct(t_bar *a)
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
	a->player->posX = 0;
	a->player->posY = 0;
	a->player->xP = 0;
	a->player->yP = 0;
	a->ray->hit = 0;
}

void		f1(char *line, t_bar *a)
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

char	**readbuf(t_list **head, int size, t_bar *a)
{
	char	**map = malloc((size + 1) * sizeof(char*));
	int y = -1;

	t_list  *tmp = *head;

	while (tmp)
	{
		map[++y] = tmp->content;
		tmp = tmp->next;
	}
	y = search(map) - 1;
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