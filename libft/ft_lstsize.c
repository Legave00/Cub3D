#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int a;

	a = 0;
	while (lst)
	{
		lst = lst->next;
		a++;
	}
	return (a);
}
