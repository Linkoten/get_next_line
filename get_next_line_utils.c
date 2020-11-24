/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:09:43 by pbrochar          #+#    #+#             */
/*   Updated: 2020/11/24 20:04:49 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdest;

	printf("src = %s\n", src);
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
	printf("dst = %s\n", *dst);
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

void	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	cursize;

	printf("ptr = %s\n", ptr);
	if (ptr == 0)
		return (malloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = malloc(newsize);
	ft_memcpy(ptr, newptr, cursize);
	printf("newptr = %s\n", newptr);
	free(ptr);
	return (newptr);
}
/*
char		*ft_realloc(char *src, size_t size)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	new = ft_memcpy(new, src, size);
	new[size] = '\0';
	free(src);
	return (new);
}*/
