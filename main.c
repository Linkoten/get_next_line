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
	char *line4;
	char *line5;
	char *line6;
	char *line7;
	int fd;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);

	get_next_line(fd, &line2);
	printf("%s\n", line2);

	get_next_line(fd, &line3);
	printf("%s\n", line3);

	get_next_line(fd, &line4);
	printf("%s\n", line4);
	get_next_line(fd, &line5);
	printf("%s\n", line5);
	get_next_line(fd, &line6);
	printf("%s\n", line6);
	get_next_line(fd, &line7);
	printf("%s\n", line7);
	free(line);
	free(line2);
	free(line3);
	free(line4);
	free(line5);
	free(line6);
	free(line7);

	close(fd);
}
