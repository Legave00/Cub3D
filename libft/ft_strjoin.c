#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int z)
{
	size_t		i;
	size_t		b;
	char		*a;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	b = ft_strlen(s1);
	i = 0;
	if ((a = malloc((b + z) * sizeof(char) + 1)) == NULL)
		return (NULL);
	while (i < (b + z))
	{
		if (*s1)
			a[i] = *s1++;
		else
			a[i] = *s2++;
		i++;
	}
	a[i] = '\0';
	return (a);
}
