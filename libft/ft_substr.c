#include "libft.h"

static	size_t	ft_destlen(char const *s, unsigned int start, size_t len)
{
	size_t i;

	i = 0;
	while (s[start + i] && i < len)
		i++;
	return (i);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	destlen;
	char	*dest;

	destlen = ft_destlen(s, start, len) + 1;
	i = 0;
	dest = (char *)malloc(sizeof(char) * destlen);
	if (dest == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
