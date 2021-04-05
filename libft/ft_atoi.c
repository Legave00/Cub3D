#include "libft.h"

static int	wi(char *a, char b, char c)
{
	int i;

	i = 0;
	while (*a == b || *a == c)
	{
		i++;
		a++;
	}
	return (i);
}

static int	arb(char *a, int c)
{
	unsigned long long int i;

	i = 0;
	while (*a > 47 && *a < 58)
	{
		i = i * 10 + (*a - 48);
		a++;
	}
	if (i > 999999999999999999)
	{
		if (c == -1)
			return (0);
		else
			return (-1);
	}
	return (i * c);
}

int			ft_atoi(const char *x)
{
	int		i;
	int		c;
	char	*a;

	c = 1;
	i = 0;
	a = (char *)x;
	while (*a == '\n' || *a == '\v' ||
			*a == '\t' || *a == '\f' ||
			*a == '\r' || *a == ' ')
		a++;
	if (wi(a, '+', '-') > 1)
		return (0);
	else if (wi(a, '+', '-') == 1)
	{
		if (*a == '-')
			c = -1;
		a++;
	}
	return (arb(a, c));
}
