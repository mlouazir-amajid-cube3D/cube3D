/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:54:24 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/02 19:18:45 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
	while (line[++i])
		if (line[i] != '1' && line[i] != ' ' \
		&& line[i] != '\t')
			return (1);
	return (0);
}

int	middle_lines(char *line)
{
	static int p;
	char	*tmp;
	int	i;

	i = -1;
	tmp = ft_strtrim(line, " \t");
	if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
		return (1);
	while (tmp[++i])
	{
		if (tmp[i] == 'N' || tmp[i] == 'E' \
		|| tmp[i] == 'S' || tmp[i] == 'W')
			p++;
		(p > 1 || is_map_char(tmp[i])) && (clear_all(NULL, NULL, "Invalid Map Content - More than one player", 1), 0);
	}
	return (0);
}

void	map_content_check(t_map *map, t_info *info, char *line)
{
	char	*tmp;
	int		i;
	int		size;

	(void)map;
	i = 0;
	size = 1;
	while (line)
	{
		tmp = line;
		if (i == 0)
		{
			if (first_last_lines(line))
				clear_all(NULL, NULL, "Invalid Map BORDER", 1);
		}
		else
			if (middle_lines(line))
				clear_all(NULL, NULL, "Invalid Map BORDER", 1);
		if (line[0])
			i++;
		line = get_next_line(info->fd);
		if (!line[0])
			clear_all(NULL, NULL, "Invalid Map Content - NEW LINE INSIDE OF IT", 1);
	}
	if (first_last_lines(tmp) || i == 1)
		clear_all(NULL, NULL, "Invalid Map BORDER", 1);
}
