/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:17:20 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/09 22:11:13 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (lst == NULL)
		return ;
	tmp = ft_lstlast(*lst);
	if (tmp)
	{
		ft_lstlast(*lst)->next = new;
		new->next = NULL;
	}
	else
		*lst = new;
}
