/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:18:53 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/09 18:43:29 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ls;
	size_t	ld;

	i = 0;
	j = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	if (ld >= dstsize)
		return (ls + dstsize);
	while (dst[i])
		i++;
	while ((j + i) < (dstsize - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ld + ls);
}
