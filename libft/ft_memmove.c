#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buffd;
	unsigned char	*buffc;

	if (!src || !dest)
		return (NULL);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	buffd = (unsigned char *)dest;
	buffc = (unsigned char *)src;
	while (n)
	{
		n--;
		buffd[n] = buffc[n];
	}
	return (dest);
}
