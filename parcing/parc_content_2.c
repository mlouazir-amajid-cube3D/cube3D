/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_content_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:02:59 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/13 18:22:23 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	fill_gaps(char **content)
{
	int	i;
	int	j;

	i = -1;
	while (content[++i])
	{
		j = -1;
		while (content[i][++j])
			if (content[i][j] == ' ' || content[i][j] == '\t')
				content[i][j] = '0';
	}
}

int	is_empty(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void	store_player(t_map *map, char c, int i, int j)
{
	if (c == '0')
		return ;
	map->player_pos_x = j;
	map->player_pos_y = i;
	map->orientation = c;
	map->content[i][j] = '0';
}

int	empty_space_check_helper(t_map *map, int i, int j)
{
	if (i - 1 > -1 && is_empty(map->content[i - 1][j]))
		return (1);
	if (j - 1 > -1 && is_empty(map->content[i][j - 1]))
		return (1);
	if (j + 1 < ft_strlen(map->content[i]) \
	&& is_empty(map->content[i][j + 1]))
		return (1);
	if (i + 1 < array_size(map->content) \
	&& is_empty(map->content[i + 1][j]))
		return (1);
	return (0);
}

int	empty_space_check(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->content[++i])
	{
		j = -1;
		while (map->content[i][++j])
		{
			if (is_map_char(map->content[i][j], 1))
			{
				if (empty_space_check_helper(map, i, j))
					return (1);
				store_player(map, map->content[i][j], i, j);
			}
		}
	}
	return (fill_gaps(map->content), 0);
}
