#include "libft.h"

char	*ft_strrchr(const char *c, int ch)
{
	char	*a;
	char	*str;

	str = (char *)c;
	a = NULL;
	if (ch == '\0')
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (*str != '\0')
	{
		if (*str == ch)
		{
			a = str;
		}
		str++;
	}
	return (a);
}
