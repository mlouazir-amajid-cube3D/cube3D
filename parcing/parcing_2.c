/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:57:11 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/02 12:01:44 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*give_elements(char *line)
{
	int i;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == 32 || line[i] == 9)
		i++;
	if (i == ft_strlen(line))
		return (print_error("No File Found"), exit(1), NULL);
	return (ft_substr(line, i, ft_strlen(line)));
}

int	is_already_registered(char *element)
{
	if (!element)
		return (0);
	return (print_error("Duplicated"), exit(1), 1);
}

int	check_element(char *line, char *elem, int size)
{
	if (!ft_strncmp(line, elem, size) \
	&& (size < ft_strlen(line) \
	&& (line[size] == 32 || line[size] == 9)))
		return (0);
	return (1);
}

void	verify_line(t_info *info, char *line)
{
	line = ft_strtrim(line, " \t");
	if (!check_element(line, "NO", 2) \
	&& !is_already_registered(info->no))
		info->no = give_elements(line);
	else if (!check_element(line, "SO", 2) \
	&& !is_already_registered(info->so))
		info->so = give_elements(line);
	else if (!check_element(line, "WE", 2) \
	&& !is_already_registered(info->we))
		info->we = give_elements(line);
	else if (!check_element(line, "EA", 2) \
	&& !is_already_registered(info->ea))
		info->ea = give_elements(line);
	else if (!check_element(line, "F", 1) \
	&& !is_already_registered(info->f))
		info->f = give_elements(line);
	else if (!check_element(line, "C", 1) \
	&& !is_already_registered(info->c))
		info->c = give_elements(line);
	else
		clear_all(NULL, NULL, "Invalid Element", 1);
	free(line);
}

int		is_map_content(char *buf)
{
	int	c;
	int i;

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

void	generate_colors(t_map *map, t_info *info)
{
	char	**tmp;
	int		i;
	int		red;
	int		green;
	int		blue;

	red = 0;
	green = 0;
	blue = 0;
	i = -1;
	tmp = ft_split(info->c, ',');
	while (tmp[++i])
		;
	if (i != 3)
	{
		clear_array(tmp, -1);
		clear_all(NULL, NULL, "Invalid Color", 1);
	}
	red = ft_atoi(tmp[0]);
	green = ft_atoi(tmp[1]);
	blue = ft_atoi(tmp[2]);
	map->c_col = (red << 16) | (green << 8) | (blue);
	printf("map->c_col = %d\n", map->c_col);
}

t_map	*save_map(t_info *info)
{
	t_map	*map;
	char	*buf;
	int		i;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	clear_all(map, NULL, NULL, 2);
	map->map_content = NULL;
	map->c_col = 0;
	map->f_col = 0;
	buf = get_next_line(info->fd);
	while (buf)
	{
		if (buf[0] && !is_map_content(buf))
			break ;
		if (buf[0])
			verify_line(info, buf);
		free(buf);
		buf = get_next_line(info->fd);
		i++;
	}
	free(buf);
	if (!(info->c) || !(info->f) \
	|| !(info->no) || !(info->ea) \
	|| !(info->so) || !(info->we))
		clear_all(NULL, NULL, "Invalid Map", 1);
	generate_colors(map, info);
	return (map);
}
