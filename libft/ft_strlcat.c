#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i])
		i++;
	len_dest = i;
	while (src[j] && j + i < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (j < size)
		dest[i + j] = '\0';
	if (size < len_dest)
		return (ft_strlen(src) + size);
	return (len_dest + ft_strlen(src));
}
