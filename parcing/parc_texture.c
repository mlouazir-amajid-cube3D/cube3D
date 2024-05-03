/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:14:29 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/03 16:21:49 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	texture_file_check(t_map *map, t_info *info)
{
	int	s;

	s = 64;
	mlx_inti(map);
	map->no_tex = mlx_xpm_file_to_image(map->init, info->no, &s, &s);
	map->so_tex = mlx_xpm_file_to_image(map->init, info->so, &s, &s);
	map->we_tex = mlx_xpm_file_to_image(map->init, info->we, &s, &s);
	map->ea_tex = mlx_xpm_file_to_image(map->init, info->ea, &s, &s);
	if (!map->no_tex || !map->so_tex || !map->we_tex || !map->ea_tex)
		clear_all(NULL, NULL, "Error in mlx", 1);
}
