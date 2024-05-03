/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:17:43 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/03 16:27:46 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	clear_array(char **array, int size)
{
	int	i;

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
	static t_map	*map;
	static t_info	*info;
	int				i;

	i = -1;
	if (mssg)
		print_error(mssg);
	if (status == 2)
		map = m;
	else if (status == 3)
		info = in;
	else
	{
		(1) && (free(info->c), free(info->f), free(info->so), \
		free(info->ea), free(info->we), free(info->no), close(info->fd), \
		free(info), 0);
		while (map->content && map->content[++i])
			free(map->content[i]);
		free(map->content);
		free(map);
		exit(status);
	}
}

void	print_error(char *mssg)
{
	int	i;

	i = -1;
	while (mssg[++i])
		write(2, &mssg[i], 1);
	write(2, "\n", 1);
}

int	array_size(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return (0);
	while (array[++i])
		;
	return (i);
}
