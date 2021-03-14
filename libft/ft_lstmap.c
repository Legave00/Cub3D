/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:43:12 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/10 00:40:13 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	if (!lst || !f || !(a = ft_lstnew(f(lst->content))))
		return (NULL);
	b = a;
	while (lst->next)
	{
		lst = lst->next;
		if (lst && !(a->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&b, del);
			return (NULL);
		}
		a = a->next;
	}
	return (b);
}
