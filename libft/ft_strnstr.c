#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	a;

	if (!ft_strlen(little))
		return ((char *)big);
	if (len == 0)
		return (NULL);
	a = ft_strlen(little);
	if (a > ft_strlen(big))
		return (NULL);
	i = len - a + 1;
	while (i--)
	{
		if (!(ft_strncmp(big, little, a)))
			return ((char *)big);
		else
			big++;
	}
	return (0);
}
