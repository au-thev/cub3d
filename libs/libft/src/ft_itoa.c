/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:58:05 by antheven          #+#    #+#             */
/*   Updated: 2023/12/11 14:50:56 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_n_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				n_len;
	int				is_negative;
	char			*nstr;
	unsigned int	i;

	n_len = get_n_len(n);
	i = n;
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		i = -n;
	}
	nstr = malloc(n_len + 1);
	if (!nstr)
		return (NULL);
	*(nstr + n_len--) = 0;
	while (n_len >= 0)
	{
		*(nstr + n_len--) = (i % 10) + '0';
		i /= 10;
	}
	if (is_negative)
		*nstr = '-';
	return (nstr);
}
