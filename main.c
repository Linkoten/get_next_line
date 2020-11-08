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

	line = NULL;
	line2 = NULL;
	line3 = NULL;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);	
	get_next_line(fd, &line2);
	printf("%s", line2);
	get_next_line(fd, &line3);
	printf("%s", line3);
	close(fd);
	free(line);
}
