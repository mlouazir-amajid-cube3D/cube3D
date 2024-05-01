/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:57:11 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/01 22:39:12 by mlouazir         ###   ########.fr       */
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

void	verify_line(t_map *info, char *line)
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
	{
		print_error("Invalid Element");
		exit(1);
	}
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

void	save_map(t_map *info)
{
	char	*buf;
	int		i;

	i = 0;
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
	printf("i = %d\n", i);
	free(buf);
	if (!(info->c) || !(info->f) \
	|| !(info->no) || !(info->ea) \
	|| !(info->so) || !(info->we))
	{
		print_error("Invalid Map");
		exit(1);
	}
}
