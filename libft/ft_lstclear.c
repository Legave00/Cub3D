/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:34:16 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/20 16:40:11 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *a;

	if (!lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		a = (*lst)->next;
		free(*lst);
		*lst = a;
	}
}
