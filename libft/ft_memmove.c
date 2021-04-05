#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			d;

	d = 0;
	b = (unsigned char	*)dest;
	a = (unsigned char	*)src;
	if (a == NULL && b == NULL)
		return (b);
	if (a < b)
		while ((n + 1) > 1)
		{
			b[n - 1] = a[n - 1];
			n--;
		}
	else
		while (d < n)
		{
			b[d] = a[d];
			d++;
		}
	return (b);
}
