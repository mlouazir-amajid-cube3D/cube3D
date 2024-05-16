/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:50:16 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/16 09:43:17 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	*get_texture(t_vars *v, t_render *tool)
{
	if ((tool->ray_dir_y <= 0) && tool->side)
		return (v->map->no_tex);
	if ((0 <= tool->ray_dir_y) && tool->side)
		return (v->map->so_tex);
	else if ((tool->ray_dir_x <= 0) && !tool->side)
		return (v->map->we_tex);
	else if ((0 <= tool->ray_dir_x) && !tool->side)
		return (v->map->ea_tex);
	return (NULL);
}

unsigned int	get_color(t_vars *v, t_render *tool, int text_x, int text_y)
{
	t_data			img_data;
	unsigned int	*color;
	void			*texture;

	texture = get_texture(v, tool);
	img_data.addr = mlx_get_data_addr(texture, &img_data.bits_per_pixel, \
	&img_data.line_length, &img_data.endian);
	color = (unsigned int *)(img_data.addr + (text_y * img_data.line_length) \
	+ (text_x * (img_data.bits_per_pixel / 8)));
	return (*(unsigned int *)color);
}

void	set_buff(t_vars *v, t_render *tool, double step_taken, int text_x)
{
	unsigned int	color;
	double			text_pos;
	int				text_y;
	int				y;

	text_y = 0;
	text_pos = (tool->draw_start - SCREEN_HEIGHT / 2 \
	+ tool->line_height / 2) * step_taken;
	y = tool->draw_start - 1;
	while (++y < tool->draw_end)
	{
		text_y = (int)text_pos;
		color = get_color(v, tool, text_x, text_y);
		my_mlx_pixel_put(&v->img, tool->x, y, color);
		text_pos += step_taken;
	}
}

void	put_texture(t_vars *v, t_render *tool)
{
	double	step_taken;
	double	wall_point;
	int		text_x;

	if (!tool->side)
		wall_point = v->pos_y + tool->perp_wall_distance * tool->ray_dir_y;
	else
		wall_point = v->pos_x + tool->perp_wall_distance * tool->ray_dir_x;
	wall_point -= floor(wall_point);
	text_x = (int)(wall_point * 64.f);
	if ((!tool->side && tool->ray_dir_x > 0) \
	|| (tool->side && tool->ray_dir_y < 0))
		text_x = 64 - text_x - 1;
	step_taken = 1.0 * 64 / tool->line_height;
	set_buff(v, tool, step_taken, text_x);
}
