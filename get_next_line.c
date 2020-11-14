#include "get_next_line.h"
#include <stdio.h>

static	void	ft_line_tool(char **line, size_t *a, int *i, t_gnl *gnl)
{
	*line = ft_realloc(*line, ft_strlen(*line) + *a);
	ft_strlcat(*line, &(gnl->buf[gnl->pos]), ft_strlen(*line) + *a);
	gnl->pos = *i + 1;
	*i = 0;
	*a = 1;
}

static	int		get_current_line(t_gnl *gnl, char **line)
{
	int		i;
	int		ret;
	size_t	a;

	a = 1;
	i = gnl->pos;
	while (gnl->buf[i] != '\n')
	{
		if (gnl->buf[i] == '\0')
		{
			ft_line_tool(line, &a, &i, gnl);
			ret = read(gnl->fd, gnl->buf, BUFF_SIZE);
			gnl->buf[ret] = '\0';
			gnl->pos = 0;
		}
		if (gnl->buf[i] == '\n' || ret == 0)
			break ;
		a++;
		i++;
	}
	ft_line_tool(line, &a, &i, gnl);
	if (ret < 1)
		return (ret);
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
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->pos = 0;
	temp = ft_lstnew(new);
	ft_lstadd_back(lst, temp);
	return ((t_gnl *)(temp->content));
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*lst;
	t_gnl			*gnl;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	*line = malloc(sizeof(char));
	if (*line == NULL)
		return (-1);
	*line[0] = '\0';
	gnl = get_gnl(fd, &lst);
	if (gnl == NULL)
		return (-1);
	ret = get_current_line(gnl, line);
	return (ret);
}
