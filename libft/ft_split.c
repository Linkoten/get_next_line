#include "libft.h"

static char	*ft_strndup(char *s, int size)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i] && i < size)
		i++;
	tab = (char *)malloc(sizeof(char) * size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < size)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int			cmp(char c, char d)
{
	if (c == d)
		return (1);
	return (0);
}

int			word_len(char *s, char c)
{
	int a;

	a = 0;
	while (!(cmp(c, s[a])) && s[a])
		a++;
	return (a);
}

int			word_count(char *s, char c)
{
	int i;
	int wc;

	wc = 0;
	i = 0;
	while (s[i])
	{
		if ((cmp(c, s[i]) && !cmp(c, s[i + 1]))
				|| (!cmp(c, s[i]) && !s[i + 1]) || !s[i + 1])
			wc++;
		i++;
	}
	if (wc == 0)
		return (1);
	return (wc);
}

char		**ft_split(char *s, char c)
{
	char	**tab;
	int		j;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (j < word_count(s, c) && s[i])
	{
		while (cmp(c, s[i]) && s[i])
			i++;
		if (!s[i])
			break ;
		tab[j] = ft_strndup(&s[i], word_len(&s[i], c));
		j++;
		i += word_len(&s[i], c);
	}
	tab[j] = 0;
	return (tab);
}
