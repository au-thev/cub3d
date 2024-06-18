/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:37:31 by antheven          #+#    #+#             */
/*   Updated: 2023/12/07 13:49:43 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	new = malloc(ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	if (s1)
		while (*s1)
			*(new + i++) = *s1++;
	if (s2)
		while (*s2)
			*(new + i++) = *s2++;
	*(new + i) = 0;
	return (new);
}
