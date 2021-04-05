#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			b;

	b = 0;
	a = (unsigned char *)s;
	while (b < n)
	{
		a[b] = '\0';
		b++;
	}
	return (a);
}
