/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:18:17 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/12 17:55:16 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	start_dda(t_vars *v, t_render *tool)
{
	tool->side = 0;
	while (1)
	{
		if (tool->ray_dir_x < tool->ray_dir_y)
		{
			tool->side_dist_x += tool->delta_dist_x;
			tool->map_x += tool->step_x;
			tool->side = 0;
		}
		else if (tool->ray_dir_y < tool->ray_dir_x)
		{
			tool->side_dist_y += tool->delta_dist_y;
			tool->map_y += tool->step_y;
			tool->side = 1;
		}
		if (v->map->content[tool->map_y][tool->map_x] \
			&& v->map->content[tool->map_y][tool->map_x] != '0')
				break;
	}
	if (tool->side)
		tool->perp_wall_distance = tool->side_dist_y - tool->delta_dist_y;
	else
		tool->perp_wall_distance = tool->side_dist_x - tool->delta_dist_x;
	tool->line_height = (int)(SCREEN_HEIGHT / tool->perp_wall_distance);
	// printf("tool->perpwallt  %f || tool->line_height  %d\n", tool->perp_wall_distance, tool->line_height);
}

void	set_dist(t_vars *v, t_render *tool)
{
	tool->delta_dist_x = abs_d(1 / tool->ray_dir_x);
	tool->delta_dist_y = abs_d(1 / tool->ray_dir_y);
	tool->map_x = (int)v->pos_x;
	tool->map_y = (int)v->pos_y;
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

int renderer(t_vars *v)
{
	t_render	*tool;
	int			w;
	
	w = 0;
	tool = malloc(sizeof(t_render));
	clear_img(&v->img);
	while (w < SCREEN_WIDTH)
	{
		tool->camera_x = 2 * w / (double)w - 1;
		tool->ray_dir_x = v->dir_x + v->plane_x * tool->camera_x;
		tool->ray_dir_y = v->dir_y + v->plane_y * tool->camera_x;
		set_dist(v, tool);
		start_dda(v, tool);
		tool->draw_start = SCREEN_HEIGHT / 2 - tool->line_height / 2;
		(tool->draw_start < 0) && (tool->draw_start = 0);
		tool->draw_end = SCREEN_HEIGHT / 2 + tool->line_height / 2;
		(tool->draw_end >= SCREEN_HEIGHT) && (tool->draw_end = SCREEN_HEIGHT - 1);
		printf("tool->draw_start %d || tool->draw_end %d || tool->line_height %d || tool->ray_dir_x %f ||  tool->ray_dir_y %f\n", tool->draw_start, tool->draw_end, tool->line_height, tool->ray_dir_x, tool->ray_dir_y);
		if (tool->side)
			draw_verline(&v->img, w, tool->draw_start, tool->draw_end, 5000);
		else
			draw_verline(&v->img, w, tool->draw_start, tool->draw_end, 9999);
		v->time++;
		v->move_speed = 0.4;
		v->rot_speed = 0.2;
		w++;
	}
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->img.img, 0, 0);
	return 0;
}

void	set_vector(t_map *map, t_vars *v)
{
	if (map->orientation == 'N')
	{
		v->dir_x = 0;
		v->dir_y = 1;
	}
	else if (map->orientation == 'S')
	{
		v->dir_x = 0;
		v->dir_y = -1;
	}
	else if (map->orientation == 'E')
	{
		v->dir_x = 1;
		v->dir_y = 0;
	}
	else if (map->orientation == 'W')
	{
		v->dir_x = -1;
		v->dir_y = 0;
	}
	v->pos_x = map->player_pos_x + .3f;
	v->pos_y = map->player_pos_y + .3f;
	v->plane_x = 0;
	v->plane_y = .66f;
}

int	re_init(t_map *map)
{
	t_vars v;

	set_vector(map, &v);
	v.move_speed = 0;
	v.rot_speed = 0;
	v.map = map;
	v.mlx = map->init;
	mlx_do_key_autorepeaton(map->init);	
	v.mlx_win = mlx_new_window(v.map->init, SCREEN_WIDTH, SCREEN_HEIGHT, "cube3d"),
	mlx_key_hook(v.mlx_win, key_hook, &v);
	v.img.img = mlx_new_image(v.map->init, 1920, 1080);
	v.img.addr = mlx_get_data_addr(v.img.img, &v.img.bits_per_pixel, &v.img.line_length,
	&v.img.endian);
	v.img.F = map->f_col;
	v.img.C = map->c_col;
	renderer(&v);
	mlx_loop_hook(v.map->init, renderer, &v);
	mlx_loop(v.map->init);
	return (0);
}
