#include "libft.h"

static long int		modul(int n)
{
	long int a;

	a = n;
	if (n >= 0)
		return (a);
	else
		return (-a);
}

static char			*zap(long int n, long int i, char *a)
{
	if (n >= 0)
		while (i > 0)
		{
			a[i - 1] = (n % 10 + 48);
			i--;
			n = n / 10;
		}
	else
		while (i > 0)
		{
			a[i] = (-n % 10 + 48);
			i--;
			n = n / 10;
		}
	return (a);
}

void				ft_putnbr_fd(int n, int fd)
{
	long int		i;
	char			a[100000];
	long int		s;

	i = 1;
	s = modul(n);
	while (s > 9)
	{
		i++;
		s = s / 10;
	}
	if (n < 0)
	{
		*a = '-';
		a[i + 1] = '\0';
	}
	else
		a[i] = '\0';
	ft_putstr_fd(zap(n, i, a), fd);
}
