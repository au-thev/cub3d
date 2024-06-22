/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:25:30 by antheven          #+#    #+#             */
/*   Updated: 2024/06/22 18:18:25 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static int	count_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			i++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	int		i;
	char **const	tab = ft_calloc((count_words(s, c) + 1), sizeof(char *));

	if (tab == NULL)
		return (NULL);
	while (*s == c)
		s++;
	if (*s == '\0')
		return (tab);
	str = ft_strdup(s);
	if (str == NULL)
		return (free(tab), NULL);
	*tab = str;
	i = 0;
	while (ft_strchr(str, c))
	{
		str = ft_strchr(str, c);
		while (*str == c)
			*str++ = 0;
		if (*str == '\0')
			break ;
		*(tab + ++i) = str;
	}
	return (tab);
}
