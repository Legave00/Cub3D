/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:58:14 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/24 07:29:04 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX1/mlx.h"
#include "../cub.h"
#include "../libft/libft.h"

void	freeall(t_bar *a, t_player *player)
{
	free(a->sprite);
	free(a->map);
	free(player->perpmass);
}

void	ifn(void *a)
{
	if (a == NULL)
	{
		printf("ошибка аллоцирования\n");
		exit(0);
	}
}

void	ft_swap(int *fir, int *sec)
{
	int	tmp;

	tmp = *fir;
	*fir = *sec;
	*sec = tmp;
}

int	*sort(int *massdist, t_bar *a)
{
	int	i;
	int	j;
	int	*massdist2;

	i = -1;
	massdist2 = malloc(a->kolspr * sizeof(int));
	ifn(massdist2);
	while (++i < a->kolspr)
		massdist2[i] = i;
	i = -1;
	while (++i < a->kolspr)
	{
		j = i;
		while (++j < a->kolspr)
		{
			if (massdist[i] < massdist[j])
			{
				ft_swap(&massdist2[i], &massdist2[j]);
				ft_swap(&massdist[i], &massdist[j]);
			}
		}
	}
	free(a->texturka.massdist);
	a->texturka.massdist = massdist2;
	return (massdist2);
}

void	scsh(t_bar *a)
{
	casting(a);
	render_next_frame(a);
	screenshot(a);
}
