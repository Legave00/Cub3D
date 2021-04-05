#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	b;
	size_t			d;

	a = (unsigned char *)s;
	b = (unsigned char)c;
	d = 0;
	while (d < n)
	{
		if (*a == b)
			return (a);
		a++;
		d++;
	}
	return (0);
}
