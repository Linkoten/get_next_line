#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
			a = i;
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (!needle[j])
				return ((char *)&haystack[a]);
		}
		i++;
	}
	return (NULL);
}
