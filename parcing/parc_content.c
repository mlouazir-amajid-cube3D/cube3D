/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:54:24 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/03 20:21:08 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	add_line(t_map *map, char *line)
{
	char		**new_map;
	static int	length;
	int			i;

	if ((length + 2) >= map->size)
		map->size *= 2;
	new_map = malloc(sizeof(char *) * map->size);
	(!new_map) && (clear_all(NULL, NULL, "Fail in malloc", 1), 0);
	i = 0;
	while (map->content && map->content[i])
	{
		new_map[i] = map->content[i];
		i++;
	}
	new_map[i++] = line;
	new_map[i] = NULL;
	free(map->content);
	map->content = new_map;
	length++;
}

int	is_map_char(char c, int pass)
{
	if (!pass)
		return (c == '1' || c == '0' || c == ' ' \
		|| c == '\t' || c == 'N' || c == 'S' \
		|| c == 'E' || c == 'W');
	return (c == '0' || c == 'N' || c == 'S' \
		|| c == 'E' || c == 'W');
}

int	first_last_lines(t_map *map, char *line, int pass)
{
	int	i;

	i = -1;
	if (!line)
		return (clear_all(NULL, NULL, "Not a valid border", 1), 1);
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ' \
		&& line[i] != '\t')
		{
			(!pass) && (free(line), 0);
			return (clear_all(NULL, NULL, "Not a valid border", 1), 1);
		}
	}
	(!pass) && (add_line(map, line), 0);
	return (0);
}

int	middle_lines(t_map *map, char *line, int *p)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strtrim(line, " \t");
	if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
		return (free(tmp), free(line), clear_all(NULL, NULL, \
		"Not a valid border", 1), 1);
	while (tmp[++i])
	{
		if (tmp[i] == 'N' || tmp[i] == 'E' \
		|| tmp[i] == 'S' || tmp[i] == 'W')
			*p += 1;
		(*p > 1) && (free(tmp), free(line), clear_all(NULL, NULL, \
		"Map with ore than one player", 1), 0);
		(!is_map_char(tmp[i], 0)) \
		&& (free(tmp), free(line), \
		clear_all(NULL, NULL, "Not a valid element", 1), 0);
	}
	return (free(tmp), add_line(map, line), 0);
}

void	map_content_check(t_map *map, t_info *info, char *line)
{
	char	*tmp;
	int		p;
	int		a;

	tmp = NULL;
	a = 0;
	p = 0;
	first_last_lines(map, line, 0);
	line = get_next_line(info->fd);
	while (line)
	{
		if (line[0])
		{
			tmp = line;
			middle_lines(map, line, &p);
			(a) && (clear_all(NULL, NULL, \
			"Invalid content", 1), 0);
		}
		(!line[0]) && (a = 1, free(line), 0);
		line = get_next_line(info->fd);
	}
	first_last_lines(map, tmp, 1);
	(p == 0) && (clear_all(NULL, NULL, "Map with no player", 1), 0);
	(empty_space_check(map->content)) \
	&& (clear_all(NULL, NULL, "Space next to a char", 1), 0);
}
