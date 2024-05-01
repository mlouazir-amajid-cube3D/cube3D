/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:13:18 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 21:35:53 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(int ac, char **av)
{
	t_map	*info;

	if (ac != 2 || map_name_check(av[1]))
		return (print_error("Invalid Arguments"), 1);
	info = malloc(sizeof(t_map));
	if (!info)
		return (print_error("Undefiened Error"), 1);
	info->filename = av[1];
	info->fd = open(info->filename, O_RDONLY);
	if (info->fd == -1)
		return (print_error("Error in file descriptor"), 1);
	save_map(info);
	return 0;
}
