/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:18 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/01 22:38:25 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void ll () 
{
	system("leaks cub3D");
}

int main(int ac, char **av)
{
	atexit(ll);
	t_map	*info;

	if (ac != 2 || map_name_check(av[1]))
		return (print_error("Invalid Arguments"), 1);
	info = malloc(sizeof(t_map));
	if (!info)
		return (print_error("Undefiened Error"), 1);
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
	save_map(info);
	printf("%s\n", info->c);
	printf("%s\n", info->f);
	printf("%s\n", info->ea);
	printf("%s\n", info->we);
	printf("%s\n", info->so);
	printf("%s\n", info->no);
	free(info->c);
	free(info->f);
	free(info->so);
	free(info->we);
	free(info->ea);
	free(info->no);
	close(info->fd);
	free(info);
	return 0;
}
