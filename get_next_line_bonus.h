/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:14:40 by pbrochar          #+#    #+#             */
/*   Updated: 2021/02/14 12:08:21 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	char			buf[BUFFER_SIZE + 1];
	unsigned int	pos;
	int				fd;
}				t_gnl;

int				get_next_line(int fd, char **line);
void			ft_lstadd_back(t_list **alst, t_list *new);
char			*ft_realloc(char *src, size_t newsize);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_strccat(t_gnl *gnl, char **dst);
size_t			ft_strclen(char *str);
t_list			*ft_lstnew(void *content);
#endif
