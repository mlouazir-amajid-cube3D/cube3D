/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:16:55 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 16:48:46 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	map_name(char *filename)
{
	int	l;

	l = ft_strlen(filename) - 1;
	if (filename[l] != 'b' || (l - 1 >= 0 && filename[l - 1] != 'u') \
	|| (l - 2 >= 0 && filename[l - 2] != 'c') || (l - 3 >= 0 && filename[l - 3] != '.'))
		return (print_error("Invalid Map Name"), exit(1), 1);
	return (0);
}
