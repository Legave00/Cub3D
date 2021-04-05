#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*a;

	i = 0;
	a = (char*)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (a == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		a[i] = str[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
