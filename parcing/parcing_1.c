/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:55 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 17:54:16 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int map_name_check(char *filename)
{
	const long size = ft_strlen(filename);
	const int ex_size = ft_strlen(".cub");
	if(size <= ex_size)
		return 1;
	if(ft_strncmp(filename + size - ex_size, ".cub", ex_size) != 0)
	{
		return 1;	
	}
	return 0;
}
