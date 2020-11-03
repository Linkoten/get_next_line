#include "get_next_line.h"
#include <stdio.h>


int		get_buf(t_gnl **current, char **line)
{
	int ret;

	ret = read((*current)->fd, (*current)->buf, BUFF_SIZE);
	if (ret < 0)
		return (0);
	else
		*line = ft_strdup((*current)->buf);
	return (1);
}

t_gnl	*get_gnl(int filed, t_list *lst)
{
	t_list	*temp;
	t_gnl	*new;

	new = NULL;
	temp = lst;
	while (temp)
	{
		if ((((t_gnl *)(temp->content)))->fd == filed)
			return (temp->content);
		temp = temp->next;
	}
	ft_lstadd_back(&lst, ft_lstnew(new));
	new = malloc(sizeof(t_gnl));
	new->fd = filed;
	return (new);
}

int	get_next_line(const int fd, char **line)
{
	static	t_list	*lst;
	t_gnl			*gnl;

	if (fd < 0 || !line)
		return (-1);
	gnl = get_gnl(fd, lst);
	if (!get_buf(&gnl, line))
		return (0);
	return (1);
}
