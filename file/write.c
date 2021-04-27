/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:22:27 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 07:20:04 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	verline(t_wall *wall, t_bar *a, t_texturka *texturka)
{
	int			i;
	int			color;
	double		step;
	float		texpos;

	i = -1;
	step = ((double)texturka->hight / (double)a->wall.linehight);
	texpos = (wall->drawstart - (a->h / 2) + a->wall.linehight / 2) * step;
	while (++i < wall->drawstart)
		mmpp(a, a->x, i, wall->ceiling);
	i = wall->drawstart - 1;
	while (++i <= wall->drawend)
	{
		a->texy = (int)texpos & (texturka->hight - 1);
		texpos += step;
		color = *(unsigned int *)(texturka->addr
				+ (a->texy * texturka->ll + a->texx * (texturka->bpp / 8)));
		mmpp(a, a->x, i, color);
	}
	i = wall->drawend - 1;
	while (++i <= a->h)
		mmpp(a, a->x, i, wall->floor);
}

void	mmpp(t_bar *a, int x, int y, int color)
{
	char	*dst;

	if (x < a->w && y < a->h)
	{
		dst = a->win.addr + (y * a->win.ll + x * (a->win.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	resalutioncheck(char *line, t_bar *a, int i, double num)
{
	defstruct(a);
	line++;
	line = runspace(line);
	while (*line)
	{
		if (*line > 47 && *line <= 57)
		{
			num = sum(&line, a, 10, num);
			i++;
			if (a->w == -1)
			{
				a->w = num;
				num = 0;
			}
			else if (a->h == -1)
			{
				a->h = num;
				num = 0;
			}
			line = runspace(line);
		}
		else
			printerror("мусор в резалюшине");
	}
	rescheck(a, a->w, a->h, i);
}

void	textcheck2(char *c, t_way *way)
{
	if (*c == 'N' && *(c + 1) == 'O'
		&& (*(c + 2) == ' ' || *(c + 2) == '\t') && !way->no)
		way->no = runspace(c + 2);
	else if (*c == 'S' && *(c + 1) == 'O'
		&& (*(c + 2) == ' ' || *(c + 2) == '\t') && !way->so)
		way->so = runspace(c + 2);
	else if (*c == 'W' && *(c + 1) == 'E'
		&& (*(c + 2) == ' ' || *(c + 2) == '\t') && !way->we)
		way->we = runspace(c + 2);
	else if (*c == 'E' && *(c + 1) == 'A'
		&& (*(c + 2) == ' ' || *(c + 2) == '\t') && !way->ea)
		way->ea = runspace(c + 2);
	else if (*c == 'S' && (*(c + 1) == ' ' || *(c + 1) == '\t') && !way->s)
		way->s = runspace(c + 2);
	else
		printerror("повтор параметра или его невалидная запись");
}

void	checkfloor( char *c, t_wall *wall)
{
	if (*c == 'C' && (*(c + 1) == ' ' || *(c + 1) == '\t')
		&& (wall->ceiling == -1))
	{
		c = runspace(c + 1);
		wall->ceiling = numbrcheck(c);
	}
	else if (*c == 'F' && (*(c + 1) == ' ' || *(c + 1) == '\t')
		&& (wall->floor == -1))
	{
		c = runspace(c + 1);
		wall->floor = numbrcheck(c);
	}
	else
		printerror("повтор параметра или его невалидная запись");
}
