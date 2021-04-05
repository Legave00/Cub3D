#include "libft.h"

static int	f1(const char *s, char c)
{
	size_t	i;
	int		b;

	i = 0;
	b = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			b++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (b);
}

static char	*f3(char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
		s++;
	return (s);
}

static char	*f2(char *a, char c)
{
	int		i;
	char	*b;
	int		d;

	i = 0;
	d = 0;
	while (a[i] != c && a[i] != '\0')
		i++;
	if ((b = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	while (d < i)
	{
		b[d] = a[d];
		d++;
	}
	b[d] = '\0';
	return (b);
}

static void	freeall(char **a, int d)
{
	while (d >= 0)
	{
		if (a[d])
			free(a[d]);
		d--;
	}
}

char		**ft_split(char const *s, char c)
{
	char	**a;
	char	*b;
	int		d;

	d = 0;
	if (!s || (a = (char **)malloc(sizeof(char *) * (f1(s, c) + 1))) == NULL)
		return (NULL);
	b = (char*)s;
	while (*b != '\0')
		if (*b != c)
		{
			a[d] = f2(b, c);
			if (a[d] == NULL)
			{
				freeall(a, d - 1);
				free(a);
				return (NULL);
			}
			d++;
			b = f3(b, c);
		}
		else
			b++;
	a[d] = NULL;
	return (a);
}
