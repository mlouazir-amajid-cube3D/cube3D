/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:03:24 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/12 07:17:02 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	int		l;

	d = (char *)dst;
	s = (char *)src;
	l = len;
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (l > 0)
		{
			d[l - 1] = s[l - 1];
			l--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
