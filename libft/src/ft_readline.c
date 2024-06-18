/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:54:10 by hgirard           #+#    #+#             */
/*   Updated: 2024/05/23 14:57:56 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define BUFFER_SIZE	1024

char	*read_buffer(int fd, char *buffer)
{
	char	*temp;
	int		n;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	n = 1;
	while (!ft_strchr(buffer, '\n') && n != 0)
	{
		n = read(fd, temp, BUFFER_SIZE);
		if (n == -1)
		{
			free(temp);
			return (0);
		}
		if (n == 0)
		{
			free(temp);
			return (buffer);
		}
		temp[n] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static size_t	strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*trim_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || (strlen2(buffer) - i) == 1)
	{
		free(buffer);
		return (NULL);
	}
	trim = malloc(sizeof(char) * (strlen2(buffer) - i));
	if (!trim)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		trim[j++] = buffer[i++];
	trim[j] = '\0';
	free(buffer);
	return (trim);
}

char	*ft_readline(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (0);
	line = get_line(buffer);
	buffer = trim_buffer(buffer);
	if (ft_strchr(line, '\n'))
		*ft_strchr(line, '\n') = '\0';
	return (line);
}
