/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:22:49 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/08 21:04:26 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *ll, size_t len)
{
	size_t	nl;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0 && !s1)
		return (NULL);
	nl = ft_strlen(ll);
	if (nl == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == ll[j])
		{
			while (s1[i + j] == ll[j] && s1[i + j] && ll[j] && (i + j) < len)
				j++;
			if (j == nl)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
