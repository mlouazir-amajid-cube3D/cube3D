/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:57:11 by mlouazir          #+#    #+#             */
/*   Updated: 2024/04/30 21:37:18 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	save_map(t_map *info)
{
	char	*buf ;

	buf = get_next_line(info->fd);
	while (buf)
	{
		printf("%s", buf);
		buf = get_next_line(info->fd);
	}
	
}