/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:14:29 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/16 17:16:01 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	texture_file_check_helper(t_map *map)
{
	if (!map->no_tex || !map->so_tex || !map->we_tex || !map->ea_tex)
	{
		(map->no_tex) && (mlx_destroy_image(map->init, map->no_tex), 0);
		(map->so_tex) && (mlx_destroy_image(map->init, map->so_tex), 0);
		(map->we_tex) && (mlx_destroy_image(map->init, map->we_tex), 0);
		(map->ea_tex) && (mlx_destroy_image(map->init, map->ea_tex), 0);
		clear_all(NULL, NULL, "Error in mlx", 1);
	}
}

void	texture_file_check(t_map *map, t_info *info)
{
	int	w;
	int	h;

	mlx_inti(map);
	while (1)
	{
		map->no_tex = mlx_xpm_file_to_image(map->init, info->no, &w, &h);
		if (w > 64 || h > 64)
			break ;
		map->so_tex = mlx_xpm_file_to_image(map->init, info->so, &w, &h);
		if (w > 64 || h > 64)
			break ;
		map->we_tex = mlx_xpm_file_to_image(map->init, info->we, &w, &h);
		if (w > 64 || h > 64)
			break ;
		map->ea_tex = mlx_xpm_file_to_image(map->init, info->ea, &w, &h);
		if (w > 64 || h > 64)
			map->ea_tex = NULL;
		break ;
	}
	texture_file_check_helper(map);
}
