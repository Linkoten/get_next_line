#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
	int fd;
//	(void)av;	
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while(get_next_line(fd, &line) != 0)
		printf("|%s|\n", line);
//	return (0);
//	printf("input user name : \n");
//	get_next_line(0, &line);
//	printf("user name : %s\\n\n", line);
//	get_next_line(fd, &line);
//	printf("MAIN : %s\\n\n", line);
	close(fd);
	free(line);	
}
