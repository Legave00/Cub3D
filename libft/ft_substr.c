#include "libft.h"

static char	*f1(char *a, const char *s, unsigned int start, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		a[i] = s[start];
		i++;
		start++;
	}
	a[len] = '\0';
	return (a);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;
	unsigned int	b;

	i = 0;
	if (!s || s == NULL)
		return (NULL);
	if ((ft_strlen(s) - start - 1) >= len)
		b = len + 1;
	else
		b = ft_strlen(s) - start + 1;
	if ((a = malloc(b * sizeof(char))) == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		a[0] = '\0';
		return (a);
	}
	return (f1(a, s, start, len));
}
