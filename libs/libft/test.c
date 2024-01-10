#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*line;
	fd = open(av[1], O_RDONLY);
	line = 1;
	while (line)
	{
		line = ft_readline(fd);
		if (line)
			printf("%s\n", line);
		free(line);
	}
}
