#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char*)malloc(size * number);
	if (a == NULL)
		return (NULL);
	while (i < number * size)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
