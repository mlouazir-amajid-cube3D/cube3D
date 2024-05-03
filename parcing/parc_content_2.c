/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_content_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:02:59 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/03 16:07:33 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_empty(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

int	empty_space_check(char **content)
{
	int	i;
	int	j;

	i = -1;
	while (content[++i])
	{
		j = -1;
		while (content[i][++j])
		{
			if (is_map_char(content[i][j], 1))
			{
				if (i - 1 > -1 && is_empty(content[i - 1][j]))
					return (1);
				if (j - 1 > -1 && is_empty(content[i][j - 1]))
					return (1);
				if (j + 1 < ft_strlen(content[i]) \
				&& is_empty(content[i][j + 1]))
					return (1);
				if (i + 1 < array_size(content) && is_empty(content[i + 1][j]))
					return (1);
			}
		}
	}
	return (0);
}
