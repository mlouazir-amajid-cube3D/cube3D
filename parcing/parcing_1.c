/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:55 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 16:40:02 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	map_name(char *filename)
{
	int	l;

	l = ft_strlen(filename) - 1;
	if (filename[l] != 'b' || filename[l - 1] != 'u' \
	|| filename[l - 2] != 'c' || filename[l - 3] != '.')
		return (print_error("Invalid Map Name"), exit(1), 1);
	return (0);
}
