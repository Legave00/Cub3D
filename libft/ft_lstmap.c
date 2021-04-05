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
