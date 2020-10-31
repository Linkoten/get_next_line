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
	int fd;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);

	close(fd);
	free(line);
}
