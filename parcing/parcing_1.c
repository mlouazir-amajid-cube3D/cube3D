/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajid <amajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:55 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 16:54:49 by amajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int map_name_check(char *filename)
{
	const long size = ft_strlen(filename);
	const ex_size = ft_strlen(".cub");
	if(size <= ex_size)
		return 0;
	if(ft_strncmp(filename - ex_size, ".cub", ex_size) != 0)
	{
		return 0;	
	}
}

int	map_name(char *filename)
{
	int	l;

	l = ft_strlen(filename) - 1;
	if (filename[l] != 'b' || filename[l - 1] != 'u' \
	|| filename[l - 2] != 'c' || filename[l - 3] != '.')
		return (print_error("Invalid Map Name"), exit(1), 1);
	return (0)
}
