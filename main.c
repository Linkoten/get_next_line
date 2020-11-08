/*	for open function
**	fcntl for open
**	sys for unix system ?
*/
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;

	char *line;
	char *line2;
	char *line3;
	int fd;
	int fd2;

	line = NULL;
	line2 = NULL;
	line3 = NULL;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);

	get_next_line(fd, &line);
	printf("fd : %s\n", line);	

	get_next_line(fd2, &line2);
	printf("fd2 : %s\n", line2);

	get_next_line(fd, &line3);
	printf("fd : %s\n", line3);
	close(fd);
	close(fd2);
	free(line);
}
