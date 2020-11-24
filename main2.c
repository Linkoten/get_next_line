#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
//	int fd;
	(void)av;	
	(void)ac;
//	fd = open(av[1], O_RDONLY);
	while(get_next_line(0, &line) == 1)
		printf("|%s|\n", line);
//	return (0);
//	printf("%d\n", get_next_line(fd, &line));
//	printf("%d\n", get_next_line(1, &line));
//	get_next_line(0, &line);
//	close(fd);
	free(line);	
}
