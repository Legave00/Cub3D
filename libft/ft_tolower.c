#include "libft.h"

int	ft_tolower(int a)
{
	char b;

	if (a > 64 && a < 91)
	{
		b = a + 32;
		return (b);
	}
	return (a);
}
