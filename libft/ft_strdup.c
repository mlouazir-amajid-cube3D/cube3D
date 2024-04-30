/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:29:25 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/07 10:11:20 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		l;

	l = ft_strlen(s1);
	str = malloc(l + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, l);
	str[l] = '\0';
	return (str);
}
