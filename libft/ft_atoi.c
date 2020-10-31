#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	int				s;
	size_t			nbr;

	i = 0;
	nbr = 0;
	s = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (ft_isdigit((int)nptr[i]))
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		i++;
	}
	return (nbr * s);
}
