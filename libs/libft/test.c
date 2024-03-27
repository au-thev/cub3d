/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:56:30 by coltcivers        #+#    #+#             */
/*   Updated: 2024/03/20 00:56:45 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
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
