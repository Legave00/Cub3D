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
