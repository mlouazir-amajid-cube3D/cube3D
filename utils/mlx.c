/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajid <amajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:16:12 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/16 15:27:59 by amajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	mlx_inti(t_map *map)
{
	map->init = mlx_init();
	if (!(map->init))
		clear_all(NULL, NULL, "Error in mlx", 1);
}

void	*mlx_image(void *mlx_ptr, int width, int height)
{
	void	*img;

	img = mlx_new_image(mlx_ptr, width, height);
	if (!img)
		return (clear_all(NULL, NULL, "HHHMMMMM", 1), NULL);
	return (img);
}

void	*mlx_window(void *mlx_ptr)
{
	void	*win;

	win = mlx_new_window(mlx_ptr, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "cube3d");
	if (!win)
		return (clear_all(NULL, NULL, "HHHMMMMM", 1), NULL);
	return (win);
}
