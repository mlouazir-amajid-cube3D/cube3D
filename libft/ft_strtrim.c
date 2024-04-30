/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:45:06 by mlouazir          #+#    #+#             */
/*   Updated: 2023/11/08 20:51:23 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	if (!s || !set)
		return (NULL);
	l = ft_strlen(s);
	while (ft_strchr((char *)set, s[i]) && l != 0)
		i++;
	while ((l - 1) > 0 && ft_strchr((char *)set, s[l - 1]))
		l--;
	str = ft_substr(s, i, (l - i));
	if (str == NULL)
		return (NULL);
	return (str);
}
