/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:18:17 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/15 14:43:16 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	start_dda(t_vars *v, t_render *tool)
{
	tool->side = 0;
	while (1)
	{
		if (tool->side_dist_x < tool->side_dist_y)
		{
			tool->side_dist_x += tool->delta_dist_x;
			tool->map_x += tool->step_x;
			tool->side = 0;
		}
		else
		{
			tool->side_dist_y += tool->delta_dist_y;
			tool->map_y += tool->step_y;
			tool->side = 1;
		}
		if (v->map->content[tool->map_y][tool->map_x] \
		&& v->map->content[tool->map_y][tool->map_x] != '0')
			break ;
	}
	if (tool->side)
		tool->perp_wall_distance = tool->side_dist_y - tool->delta_dist_y;
	else
		tool->perp_wall_distance = tool->side_dist_x - tool->delta_dist_x;
	tool->line_height = (int)(SCREEN_HEIGHT / tool->perp_wall_distance);
}

void	set_dist(t_vars *v, t_render *tool)
{
	tool->map_x = (int)v->pos_x;
	tool->map_y = (int)v->pos_y;
	tool->delta_dist_x = abs_d(1.0f / tool->ray_dir_x);
	tool->delta_dist_y = abs_d(1.0f / tool->ray_dir_y);
	if (tool->ray_dir_x < 0)
	{
		tool->side_dist_x = (v->pos_x - tool->map_x) * tool->delta_dist_x;
		tool->step_x = -1;
	}
	else
	{
		tool->side_dist_x = (tool->map_x + 1.0 - v->pos_x) * tool->delta_dist_x;
		tool->step_x = 1;
	}
	if (tool->ray_dir_y < 0)
	{
		tool->side_dist_y = (v->pos_y - tool->map_y) * tool->delta_dist_y;
		tool->step_y = -1;
	}
	else
	{
		tool->side_dist_y = (tool->map_y + 1.0 - v->pos_y) * tool->delta_dist_y;
		tool->step_y = 1;
	}
}

int	renderer(t_vars *v)
{
	t_render	tool;
	int			x;

	x = 0;
	clear_img(&v->img);
	while (x < SCREEN_WIDTH)
	{
		tool.x = x;
		tool.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		tool.ray_dir_x = v->dir_x + v->plane_x * tool.camera_x;
		tool.ray_dir_y = v->dir_y + v->plane_y * tool.camera_x;
		set_dist(v, &tool);
		start_dda(v, &tool);
		tool.draw_start = SCREEN_HEIGHT / 2 - tool.line_height / 2;
		(tool.draw_start < 0) && (tool.draw_start = 0);
		tool.draw_end = SCREEN_HEIGHT / 2 + tool.line_height / 2;
		(tool.draw_end >= SCREEN_HEIGHT) && (tool.draw_end = SCREEN_HEIGHT);
		put_texture(v, &tool);
		v->time++;
		v->move_speed = 0.4;
		v->rot_speed = 0.2;
		x++;
	}
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->img.img, 0, 0);
	return (0);
}

int	re_init(t_map *map)
{
	t_vars	v;

	set_vector(map, &v);
	mlx_do_key_autorepeaton(map->init);
	v.mlx_win = mlx_window(v.map->init);
	v.img.img = mlx_image(v.map->init, 1920, 1080);
	v.img.addr = mlx_get_data_addr(v.img.img, &v.img.bits_per_pixel, \
	&v.img.line_length, &v.img.endian);
	v.img.f = map->f_col;
	v.img.c = map->c_col;
	mlx_key_hook(v.mlx_win, key_hook, &v);
	mlx_loop_hook(v.map->init, renderer, &v);
	mlx_loop(v.map->init);
	return (0);
}
