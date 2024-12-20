#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		x;

	x = 11;
	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (0);
	while (i < x)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
}
