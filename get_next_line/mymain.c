#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	main(int argv, char *argc[])
{
	int		fd;
	int		i;
	int		j;
	int		r;
	char	*str = "1234567890";
	char	*line;
	char	*p;


	j = 1;
	while (j < argv)
	{
		fd = open(argc[j], O_RDONLY);
		i = 1;
		printf("===========================================================<%s>===========================================================\n", argc[j]);
		while ((r = get_next_line(42, &line)) >= 0)
		{
			printf("r: %d\n", r);
			printf("%3d: %s\n", i++, line);
			free(line);
			if (r == 0)
				break ;
		}
		printf("r: %d\n", r);
		j++;
	}

	/*
	for (i = 0; i < 5; i++)
		if (!(line = (char *)malloc(sizeof(char) * 5)))
			return (0);
	free(line);
	*/

	/*
	// line = (char *)malloc(sizeof(char) * 5);
	line = strdup(strchr(str, '4'));
	line[0] = 'h';
	line[1] = 'e';
	line[2] = 0;
	printf("%p: %s\n", line, line);
	printf("%p: %s\n", str, str);
	free(line);
	// line = (char *)malloc(sizeof(char) * 3);
	printf("%p: %s\n", str, str);
	printf("%p: %s\n", line, line);
	line = strdup(strchr(str, '5'));
	printf("%p: %s\n", line, line);
	*/
	/*
	p = malloc(1);
	printf("%p\n", p);
	free(p);
	p = malloc(1);
	printf("%p\n", p);
	free(p);
	*/

	/*
	for (int i = 0; i < 20; i++)
	{
		printf("%c", *(line + i));
	}
	*/
}
