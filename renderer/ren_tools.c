/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:13:36 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/13 18:40:53 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			if (i < (SCREEN_HEIGHT / 2))
				my_mlx_pixel_put(data, j, i, data->f);
			else
				my_mlx_pixel_put(data, j, i, data->c);
			j++;
		}
		i++;
	}
}

double	abs_d(double x)
{
	if (x < 0.0F)
		return (x * -1.0F);
	return (x);
}

void	set_vector_2(t_map *map, t_vars *v)
{
	if (map->orientation == 'E')
	{
		v->plane_y = -0.66f;
		v->plane_x = 0;
		v->dir_x = 1;
		v->dir_y = 0;
	}
	else if (map->orientation == 'W')
	{
		v->plane_y = 0.66f;
		v->plane_x = 0;
		v->dir_x = -1;
		v->dir_y = 0;
	}
	v->pos_x = map->player_pos_x + .3f;
	v->pos_y = map->player_pos_y + .3f;
	v->move_speed = 0.4;
	v->rot_speed = 0.2;
	v->map = map;
	v->mlx = map->init;
}

void	set_vector(t_map *map, t_vars *v)
{
	if (map->orientation == 'N')
	{
		v->plane_y = 0;
		v->plane_x = -0.66f;
		v->dir_x = 0;
		v->dir_y = -1;
	}
	else if (map->orientation == 'S')
	{
		v->plane_y = 0;
		v->plane_x = 0.66f;
		v->dir_x = 0;
		v->dir_y = 1;
	}
	set_vector_2(map, v);
	v->original_x = SCREEN_WIDTH / 2;
}
