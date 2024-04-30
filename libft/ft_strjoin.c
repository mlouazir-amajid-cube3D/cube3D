/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:38:16 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/08 20:48:23 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	if (size == 0)
		str[0] = '\0';
	else
	{
		ft_strlcpy(str, (char *)s1, size + 1);
		if (ft_strlen(s2) == 0)
			str[size] = '\0';
		else
			ft_strlcat(str, (char *)s2, size + 1);
	}
	return (str);
}
