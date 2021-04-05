#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *a;

	a = (char *)str;
	while (*a != '\0')
	{
		if (*a == ch)
			return (a);
		a++;
	}
	if (ch == '\0')
		return (a);
	return (0);
}
