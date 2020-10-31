#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	ps = (unsigned char *)s;
	i = 0;
	while (ps[i] && i < n)
	{
		ps[i] = 0;
		i++;
	}
}
