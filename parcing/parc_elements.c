/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:27:22 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/16 11:18:08 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_already_registered(char *element)
{
	if (!element)
		return (0);
	return (print_error("Duplicated element"), exit(1), 1);
}

int	check_element(char *line, char *elem, int size)
{
	if (!ft_strncmp(line, elem, size) \
	&& (size < ft_strlen(line) \
	&& (line[size] == 32 || line[size] == 9)))
		return (0);
	return (1);
}

char	*give_elements(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == 32 || line[i] == 9)
		i++;
	tmp = ft_substr(line, i, ft_strlen(line));
	(!tmp) && (clear_all(NULL, NULL, "faille in malloc", 1), 0);
	return (tmp);
}

void	verify_line(t_info *info, char *line)
{
	line = ft_strtrim(line, " \t");
	(!line) && (clear_all(NULL, NULL, "faille in malloc", 1), 0);
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
