#include "get_next_line.h"

char 	*ft_realloc(char *src, size_t size)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	new = ft_memcpy(new, src, size);
	free(src);
	return (new);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len_dest;

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

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *plst;

	if (alst && *alst)
	{
		plst = *alst;
		while (plst->next)
			plst = plst->next;
		plst->next = new;
	}
	else if (alst)
		*alst = new;
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdest;

	if (!dest && !src)
		return (dest);
	psrc = (unsigned char *)src;
	pdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
