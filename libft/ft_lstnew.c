/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:11:28 by ydorene           #+#    #+#             */
/*   Updated: 2020/11/09 21:51:13 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *a;

	if ((a = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}
