#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a < 128)
		return (1);
	return (0);
}
