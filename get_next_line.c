#include "get_next_line.h"

int	ft_strchrlen(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static	int	nb_line;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;
	
	i = 0;
	nb_line = 0;
	(void)line;
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (ft_strchrlen(buf, 10))
			*line = ft_substr(buf, 0, ft_strchrlen(buf, 10));
		ret = read(fd, buf, BUFF_SIZE);
	}
	nb_line++;
	return (0);
}
