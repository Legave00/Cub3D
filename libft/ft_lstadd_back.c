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
