/*	for open function
**	fcntl for open
**	sys for unix system ?
*/
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;

	char *line;
	int fd;

	fd = open(av[1]);
	get_next_line(fd, &line);
}
