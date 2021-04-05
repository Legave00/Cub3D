#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			c;

	c = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (b == 0)
		if (a == NULL)
			return (NULL);
	while (c < n)
	{
		a[c] = b[c];
		c++;
	}
	return (a);
}
