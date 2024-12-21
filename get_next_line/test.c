#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		x;

	x = 10;
	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (0);
	while (i < x)
	{
		line = get_next_line(fd);
		printf("%d: %s", i + 1, line);
		free(line);
		i++;
	}
}
