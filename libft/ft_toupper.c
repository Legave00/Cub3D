#include "libft.h"

int	ft_toupper(int a)
{
	char b;

	if (a > 96 && a < 123)
	{
		b = a - 32;
		return (b);
	}
	else
		return (a);
}
