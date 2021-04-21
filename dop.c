/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:49:51 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/21 20:38:51 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void	defstruct(t_bar *a)
{
	a->fir = 0;
	a->sec = 0;
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

int	search(char **map)
{
	int	i;

	i = 1;
	while (map[i - 1][0] != 'C')
		i++;
	while (map[i][0] == '\0')
		i++;
	return (i);
}

void	reader(t_bar *a, int fd)
{
	char	*line;
	int		i;
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
