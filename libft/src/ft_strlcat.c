/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:34:39 by antheven          #+#    #+#             */
/*   Updated: 2023/12/06 13:42:58 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(char *s, int n)
{
	int	i;

	i = 0;
	while (*s && n-- > 0)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*initial_dst;
	size_t	initial_n;

	initial_dst = dest;
	initial_n = n;
	while (*dest++)
		;
	*(dest + --n) = 0;
	while (n-- > 0)
		*(dest + n) = *(src + n);
	return (ft_strnlen(initial_dst, initial_n));
}
