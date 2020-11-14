#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
	int fd;
	
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while(get_next_line(fd, &line) != 0)
		printf("%s\n", line);
	return (0);
	close(fd);
	free(line);	
}
