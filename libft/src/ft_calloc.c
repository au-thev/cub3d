/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 02:41:00 by antheven          #+#    #+#             */
/*   Updated: 2023/12/07 02:53:11 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		i;

	i = nmemb * size;
	ptr = malloc(i);
	if (!ptr)
		return (0);
	while (i-- > 0)
		*(char *)(ptr + i) = 0;
	return (ptr);
}
