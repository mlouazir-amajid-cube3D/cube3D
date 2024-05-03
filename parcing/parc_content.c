/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:54:24 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/03 11:33:54 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	add_line(t_map *map, char *line)
{
	char	**new_map;
	int		length;
	int		x;

	x = 16;
	length = array_size(map->content);
	while (x <= length)
		x *= 2;
	new_map = malloc(sizeof(char *) * x);
	x = -1;
	while (map->content && map->content[++x])
}

int	is_map_char(char c)
{
	return (c == '1' || c == '0' || c == ' ' \
	|| c == '\t' || c == 'N' || c == 'S' \
	|| c == 'E' || c == 'W');
}

int	first_last_lines(char *line)
{
	int i;

	i = -1;
	if (!line)
		return (clear_all(NULL, NULL, "Invalid Map BORDER", 1), 1);
	while (line[++i])
		if (line[i] != '1' && line[i] != ' ' \
		&& line[i] != '\t')
			return (free(line), clear_all(NULL, NULL, "Invalid Map BORDER", 1), 1);
	return (0);
}

int	middle_lines(char *line, int *p)
{
	char	*tmp;
	int	i;

	i = -1;
	tmp = ft_strtrim(line, " \t");
	if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
		return (free(tmp), free(line), clear_all(NULL, NULL, \
		"Invalid Map Content - Not a valid element", 1), 1);
	while (tmp[++i])
	{
		if (tmp[i] == 'N' || tmp[i] == 'E' \
		|| tmp[i] == 'S' || tmp[i] == 'W')
			*p += 1;
		(*p > 1) && (free(tmp), free(line), clear_all(NULL, NULL, \
		"Invalid Map Content - More than one player", 1), 0);
		(!is_map_char(tmp[i])) && (free(tmp), free(line), clear_all(NULL, NULL, \
		"Invalid Map Content - Not a valid element", 1), 0);
	}
	return (free(tmp), 0);
}

void	map_content_check(t_map *map, t_info *info, char *line)
{
	char	*tmp;
	int		i;
	int		p;
	int		a;

	(void)map;
	tmp = NULL;
	a = 0;
	p = 0;
	i = 0;
	first_last_lines(line);
	line = get_next_line(info->fd);
	while (line)
	{
		tmp = line;
		(!line[0]) && (a = 1);
		(line[0]) && (i++, 0);
		(line[0] && a) \
		&& (clear_all(NULL, NULL, "Invalid Map Content - NEW LINE INSIDE OF IT", 1), 0);
		middle_lines(line, &p);
		line = get_next_line(info->fd);
	}
	first_last_lines(tmp);
	(p == 0) && (clear_all(NULL, NULL, "Invalid Map-NoPlayer", 1), 0);
}
