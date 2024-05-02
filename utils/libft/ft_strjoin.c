/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:36:08 by amajid            #+#    #+#             */
/*   Updated: 2024/05/02 09:15:58 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	ft_memset(result, 0, s1_len + s2_len + 1);
	while (s1 && i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && j < s2_len)
		result[i++] = s2[j++];
	return (free(s1), result);
}
