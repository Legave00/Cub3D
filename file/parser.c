/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:29:34 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/27 20:29:44 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	aroundpl(t_bar *a, int i, int b)
{
	if (i != a->wall.linemap && i != a->size
		&& b != 0 && b != (ft_strlen(a->map[i]) - 1))
	{
		if ((a->map[i][b + 1] == ' ')
			|| (a->map[i][b - 1] == ' ')
			|| ((ft_strlen(a->map[i + 1]) <= b) || a->map[i + 1][b] == ' ')
			|| ((ft_strlen(a->map[i - 1]) <= b) || a->map[i - 1][b] == ' '))
			printerror("невалидная карта");
	}
	else
		printerror("невалидная карта");
}

void	mapcheck(t_bar *a, t_wall *wall)
{
	int	b;
	int	i;

	b = 0;
	i = wall->linemap - 2;
	while (++i < a->size)
	{
		b = -1;
		while (a->map[i][++b])
		{
			if (a->map[i][b] == 'N' || a->map[i][b] == 'W' ||
				a->map[i][b] == 'S' || a->map[i][b] == 'E'
				|| a->map[i][b] == '0' || a->map[i][b] == '2')
				aroundpl(a, i, b);
		}
	}
}

int	atoisec(char **a)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (**a == '\t' || **a == ' ')
		(*a)++;
	while (**a >= 48 && **a <= 57)
	{
		num = num * 10 + (**a - 48);
		(*a)++;
		i++;
	}
	while (**a == '\t' || **a == ' ')
		(*a)++;
	if (i == 0)
		num = -1;
	return (num);
}

unsigned int	numbrcheck(char	*s)
{
	unsigned int	i;
	int				j;
	unsigned int	d;

	j = 0;
	i = 0;
	d = 0;
	while (*s != '\0')
	{
		d = atoisec(&s);
		if (d > 255 || d < 0)
			printerror("невалидная запись цвета");
		i += d << (8 * (2 - j));
		++j;
		if (*s == ',' && *(s + 1) != '\0')
			s = s + 1;
		else if (*s != '\0' && *s != ' ' && *s != '\t')
			printerror("невалидная запись цвета");
	}
	if (j != 3)
		printerror("невалидная запись цвета");
	return (i);
}

void	parser(t_bar *a, int fd, char *s)
{
	int	i;

	i = 1;
	checkfile(s);
	reader(a, fd);
	if (a->map[0][0] == 'R' && (a->map[0][1] == ' ' || a->map[0][1] == '\t'))
		resalutioncheck(a->map[0], a, 0, 0);
	else
		printerror("косяк в резалюшине или файл пустой");
	textcheck(a, 0, 0, &a->wall);
	mapcheck(a, &a->wall);
}
