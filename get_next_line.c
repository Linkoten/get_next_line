#include "get_next_line.h"
#include <stdio.h>

static	int	get_current_line(t_gnl *gnl, char **line)
{
	int 	i;
	size_t 	a;
	int 	ret;

	a = 0;
	i = gnl->pos;
	*line = malloc(sizeof(char));
	*line[0] = '\0';
	if (gnl->buf[0] == '\0')
		ret = read(gnl->fd, gnl->buf, BUFF_SIZE);
	while (gnl->buf[i] != '\n')
	{
		a++;
		if (gnl->buf[i] == '\0')
		{
			*line = ft_realloc(*line, ft_strlen(*line) + a);
			ft_strlcat(*line, &(gnl->buf[gnl->pos]), a);
			ret = read(gnl->fd, gnl->buf, BUFF_SIZE);
			if (ret == -1)
				return (-1);
		}
		if (gnl->buf[i] == '\n')
		{
			*line = ft_realloc(*line, (ft_strlen(*line) + a));
			ft_strlcat(*line, &(gnl->buf[gnl->pos]), a);
			break;
		}
		i++;
	}
	gnl->pos = gnl->pos + a;
	if (ret == 0)
		return (0);
	return (1);
}

static	t_gnl	*get_gnl(int fd, t_list **lst)
{
	t_list	*temp;
	t_gnl	*new;

	temp = *lst;
	new = NULL;
	while (temp)
	{
		if (((t_gnl *)(temp->content))->fd == fd)
			return ((t_gnl *)(temp->content));
		temp = temp->next;		
	}
	new = malloc(sizeof(t_gnl));
	new->fd = fd;
	new->pos = 0;
	temp = ft_lstnew(new);
	ft_lstadd_back(lst, temp);
	return ((t_gnl *)(temp->content));
}

int	get_next_line(const int fd, char **line)
{
	static	t_list	*lst;
	t_gnl			*gnl;

	if (fd < 0 || !line)
		return (-1);
	gnl = get_gnl(fd, &lst);
	get_current_line(gnl, line);
	printf("%s\n", *line);
	return (1);
}
