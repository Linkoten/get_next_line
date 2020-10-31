#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size == 0)
		return (NULL);
	tab = (void *)malloc(sizeof(size) * nmemb);
	if (tab == NULL)
		return (NULL);
	return (tab);
}
