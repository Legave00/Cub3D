#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;

	a = (const unsigned char*)s1;
	b = (const unsigned char*)s2;
	if (n == 0)
		return (0);
	if (*a == '\0')
		return (-*b);
	else if (*b == '\0')
		return (*a);
	while (n > 1 && *a != '\0' && *b && *a == *b)
	{
		a++;
		b++;
		n--;
	}
	if (*a != *b)
		return (*a - *b);
	return (0);
}
