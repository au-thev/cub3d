/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:09:23 by antheven          #+#    #+#             */
/*   Updated: 2023/12/16 12:41:05 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_readline(int fd)
{
	char	*buffer;
	char	*cache;
	char	*swap;
	int		i;

	i = 1;
	buffer = ft_calloc(1, 2);
	cache = ft_calloc(1, 1);
	while (i > 0)
	{
		i = read(fd, buffer, 1);
		if (i <= 0)
		{
			free(buffer);
			free(cache);
			return (NULL);
		}
		if (*buffer == '\n' || *buffer == '\0')
			break ;
		swap = ft_strjoin(cache, buffer);
		free(cache);
		cache = swap;
	}
	free(buffer);
	return (cache);
}
