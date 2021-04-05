#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*a;
	int		b;

	b = 0;
	if (!s || !f)
		return (NULL);
	i = sizeof(char) * ft_strlen(s) + 1;
	if ((a = malloc(i)) == NULL)
		return (NULL);
	while (s[b] != '\0')
	{
		a[b] = f(b, s[b]);
		b++;
	}
	a[b] = '\0';
	return (a);
}
