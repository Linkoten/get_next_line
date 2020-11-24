/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:44:07 by pbrochar          #+#    #+#             */
/*   Updated: 2020/11/24 19:48:04 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			get_line(t_gnl *gnl, char **line)
{
	size_t	len;
	int		ret;

	len = 0;
	if (gnl->buf[gnl->pos] == '\0')
	{
		ret = read(gnl->fd, gnl->buf, BUFFER_SIZE);
		gnl->buf[ret] = '\0';
	}
	while (len == 0)
	{
		len = ft_strccat(gnl, line);
		if (len == 0)
		{
			ret = read(gnl->fd, gnl->buf, BUFFER_SIZE);
			gnl->buf[ret] = '\0';
		}
		if (ret < 0)
			return (-1);
		if (ret == 0)
			return (0);
	}
	return (1);
}

static t_gnl		*get_gnl(int fd, t_list **lst)
{
	t_list	*temp;
	t_list	*elem;
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
	new->buf[0] = '\0';
	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = new;
	elem->next = NULL;
	temp = elem;
	ft_lstadd_back(lst, temp);
	return ((t_gnl *)(temp->content));
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_gnl			*gnl;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((gnl = get_gnl(fd, &lst)) == NULL)
		return (-1);
	*line = malloc(sizeof(char));
	(*line)[0] = '\0';
	ret = get_line(gnl, line);
	if (ret == 0)
		return (0);
	if (ret == -1)
		return (-1);
	return (1);
}
