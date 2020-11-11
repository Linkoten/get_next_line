#include "libft.h"

char *ft_realloc(char *src, size_t size)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	new = ft_memcpy(new, src, ft_strlen(src));
	free(src);
	return (new);
}
