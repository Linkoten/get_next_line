#include "get_next_line.h"
#include <stdio.h>

static	unsigned int	ft_strchrlen(t_gnl *gnl, int c)
{
	unsigned int i;
	unsigned int a;

	a = 0;	
	i = gnl->pos;
	while (gnl->buf[i] && gnl->buf[i] != c)
	{
		i++;
		a++;
	}
	return (a);
}
/*
static	int		get_buf(t_gnl *current, char **line)
{
	int ret;
	int len;

	printf("\n ****%d ****\n", current->pos);
	printf("\n---- %d ----\n", current->fd);
	ret = read(current->fd, current->buf, BUFF_SIZE);
	len = ft_strchrlen(&current->buf[current->pos], 10);
	*line = ft_substr(current->buf, current->pos, len);
	current->pos = len;
	if (ret < 0)
		return (0);
	
	return (1);
}
*/
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
	int ret;
	unsigned int len;
	if (fd < 0 || !line)
		return (-1);
	gnl = get_gnl(fd, &lst);
	ret = read(gnl->fd, gnl->buf, BUFF_SIZE);
	len = ft_strchrlen(gnl, 10);
	*line = ft_substr(gnl->buf, gnl->pos, len);
	gnl->pos = gnl->pos + len + 1;
	(void)ret;

	return (1);
}
