/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:43:12 by ydorene           #+#    #+#             */
/*   Updated: 2021/04/14 18:08:32 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(f(lst->content));
	if (!lst || !f || !a)
		return (NULL);
	b = a;
	while (lst->next)
	{
		lst = lst->next;
		a->next = ft_lstnew(f(lst->content));
		if (lst && !a->next)
		{
			ft_lstclear(&b, del);
			return (NULL);
		}
		a = a->next;
	}
	return (b);
}
