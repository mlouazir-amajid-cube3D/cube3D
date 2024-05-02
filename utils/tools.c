/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:17:43 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/02 11:29:37 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	clear_array(char **array, int size)
{
	int i;

	i = -1;
	if (size == -1)
	{
		while (array[++i])
			free(array[i]);
	}
	else
		while (++i < size)
			free(array[i]);
	free(array);
}

void	clear_all(t_map *m, t_info *in, char *mssg, int status)
{
	static t_map *map;
	static t_info *info;
	int	i;

	i = -1;
	if (mssg)
		print_error(mssg);
	if (status == 2)
		map = m;
	else if (status == 3)
		info = in;
	else
	{
		free(info->c);
		free(info->f);
		free(info->so);
		free(info->we);
		free(info->ea);
		free(info->no);
		close(info->fd);
		free(info);
		while (map->map_content && map->map_content[++i])
			free(map->map_content[i]);
		free(map->map_content);
		free(map);
		exit(status);
	}
}

void	print_error(char *mssg)
{
	int i;

	i = -1;
	while (mssg[++i])
		write(2, &mssg[i], 1);
	write(2, "\n", 1);
}
