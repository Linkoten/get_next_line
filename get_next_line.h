#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 500

typedef struct 	s_gnl
{
	char			buf[BUFF_SIZE + 1];
	unsigned int	pos;
	int				fd;
}				t_gnl;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				get_next_line(const int fd, char **line);
void			ft_lstadd_back(t_list **alst, t_list *new);
char 			*ft_realloc(char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
#endif
