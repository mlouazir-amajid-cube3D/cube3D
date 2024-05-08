/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:57:11 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/08 18:02:34 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_map_content(char *buf)
{
	int	c;
	int	i;

	i = -1;
	c = 0;
	while (buf[++i])
	{
		if (buf[i] == 'W' \
		&& (i + 1 < ft_strlen(buf) && buf[i + 1] == 'E'))
			return (1);
		if (buf[i] != '1' && buf[i] != '0' \
		&& buf[i] != 'N' && buf[i] != 'E' \
		&& buf[i] != 'S' && buf[i] != 'W' \
		&& buf[i] != 32 && buf[i] != 9)
			return (1);
	}
	return (0);
}

char	*elements_check(t_map *map, t_info *info)
{
	char	*buf;

	buf = get_next_line(info->fd);
	(!buf) && (clear_all(NULL, NULL, "Empty file", 1), 0);
	while (buf)
	{
		if (buf[0] && !is_map_content(buf))
			break ;
		if (buf[0])
			verify_line(info, buf);
		free(buf);
		buf = get_next_line(info->fd);
		(!buf) && (clear_all(NULL, NULL, "No map content", 1), 0);
	}
	if (!(info->c) || !(info->f) \
	|| !(info->no) || !(info->ea) \
	|| !(info->so) || !(info->we))
		clear_all(NULL, NULL, "Element missing", 1);
	generate_colors(&(map->c_col), info->c);
	generate_colors(&(map->f_col), info->f);
	return (buf);
}

void	map_init(t_map **map)
{
	(*map) = malloc(sizeof(t_map));
	(!(*map)) && (clear_all(NULL, NULL, "Fail in malloc", 1), 0);
	clear_all((*map), NULL, NULL, 2);
	(*map)->content = NULL;
	(*map)->init = NULL;
	(*map)->no_tex = NULL;
	(*map)->so_tex = NULL;
	(*map)->we_tex = NULL;
	(*map)->ea_tex = NULL;
	(*map)->c_col = 0;
	(*map)->f_col = 0;
	(*map)->player_pos_x = 0;
	(*map)->player_pos_y = 0;
	(*map)->orientation = 0;
	(*map)->size = 16;
}

t_map	*save_map(t_info *info)
{
	t_map	*map;
	char	*buf;

	map = NULL;
	map_init(&map);
	buf = elements_check(map, info);
	texture_file_check(map, info);
	map_content_check(map, info, buf);
	return (map);
}
