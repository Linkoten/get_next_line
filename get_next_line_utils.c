/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:09:43 by pbrochar          #+#    #+#             */
/*   Updated: 2021/02/14 11:57:26 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void		ft_lstadd_back(t_list **alst, t_list *new)
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

size_t		ft_strclen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i + 1);
}

int			ft_strccat(t_gnl *gnl, char **dst)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = gnl->pos;
	*dst = ft_realloc(*dst, ft_strclen(&(gnl->buf[a]))
						+ ft_strclen(*dst));
	while ((*dst)[i])
		i++;
	while (gnl->buf[a] && gnl->buf[a] != '\n')
	{
		(*dst)[i] = gnl->buf[a];
		i++;
		a++;
	}
	(*dst)[i] = '\0';
	if (gnl->buf[a] == '\n')
	{
		gnl->pos = a + 1;
		return (1);
	}
	gnl->pos = 0;
	return (0);
}

char		*ft_realloc(char *src, size_t newsize)
{
	int		i;
	char	*new;

	if (!(new = malloc(sizeof(char) * newsize)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	free(src);
	return (new);
}
