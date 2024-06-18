/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:55:40 by antheven          #+#    #+#             */
/*   Updated: 2023/12/07 02:34:10 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s)
		return (0);
	while (*(unsigned char *) s && n-- > 0)
	{
		if (*(unsigned char *)s == c)
			return ((void *)s);
		s++;
	}
	return (0);
}
