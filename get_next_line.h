#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 2

typedef struct 	s_gnl
{
	char			buf[BUFF_SIZE + 1];
	unsigned int	pos;
	int				fd;
}				t_gnl;

int	get_next_line(const int fd, char **line);

#endif
