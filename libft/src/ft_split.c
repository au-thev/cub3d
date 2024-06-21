/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:25:30 by antheven          #+#    #+#             */
/*   Updated: 2024/06/18 21:19:49 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static int	count_words(const char *s, char c)
{
	int	i;

	i = 1;
	while (ft_strchr(s, c))
	{
		s = ft_strchr(s, c) + 1;
		while (*s == c)
			s++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;

	if (!s)
		return (0);
	if (!*s)
		return (0);
	while (*s == c)
		s++;
	str = ft_strdup(s);
	tab = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	*tab = str;
	i = 0;
	while (ft_strchr(str, c))
	{
		str = ft_strchr(str, c);
		while (*str == c)
			*str++ = 0;
		*(tab + ++i) = str;
	}
	*(tab + ++i) = 0;
	return (tab);
}
