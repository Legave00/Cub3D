/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:29:34 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/12 13:08:15 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "libft/libft.h"

void	f1(char *line, t_bar *a, int i, int num)
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
