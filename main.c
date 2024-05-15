/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:18 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/15 10:50:40 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void ll	() 
// {
// 	system("leaks cub3D");
// }

int	main(int ac, char **av)
{
	// atexit(ll);
	t_info	*info;
	t_map	*map;

	if (ac != 2 || map_name_check(av[1]))
		return (print_error("Invalid file name"), 1);
	info = malloc(sizeof(t_info));
	if (!info)
		return (print_error("Undefiened Error"), 1);
	clear_all(NULL, info, NULL, 3);
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->ea = NULL;
	info->c = NULL;
	info->f = NULL;
	info->filename = av[1];
	info->fd = open(info->filename, O_RDONLY);
	if (info->fd == -1)
		return (print_error("Error in file descriptor"), 1);
	map = save_map(info);
	re_init(map);
	clear_all(NULL, NULL, NULL, 0);
	return (0);
}
