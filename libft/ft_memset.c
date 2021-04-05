#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	b;
	size_t			d;

	d = 0;
	a = (unsigned char *)s;
	b = (unsigned char)c;
	if (n == 0)
		if (a == NULL)
			return (NULL);
	while (d < n)
	{
		a[d] = b;
		d++;
	}
	return (a);
}
