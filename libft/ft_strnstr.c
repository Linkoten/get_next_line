#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;
	int	a;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && n > 0)
	{
		j = 0;
		if (s1[i] == s2[j])
			a = i;
		while (s1[i] == s2[j] && n > 0)
		{
			i++;
			j++;
			n--;
			if (!s2[j])
				return ((char *)&s1[a]);
		}
		i++;
		n--;
	}
	return (NULL);
}
