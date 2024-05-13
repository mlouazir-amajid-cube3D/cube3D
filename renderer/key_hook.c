/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:29:28 by mlouazir          #+#    #+#             */
/*   Updated: 2024/05/13 18:49:20 by mlouazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	key_hook_4(int keycode, t_vars *v)
{
	double	olddir_x;
	double	old_plane_x;

	if (keycode == 123 || v->mouse_movement == -1)
	{
		olddir_x = v->dir_x;
		v->dir_x = v->dir_x * cos(v->rot_speed) - v->dir_y * sin(v->rot_speed);
		v->dir_y = olddir_x * sin(v->rot_speed) + v->dir_y * cos(v->rot_speed);
		old_plane_x = v->plane_x;
		v->plane_x = v->plane_x * \
		cos(v->rot_speed) - v->plane_y * sin(v->rot_speed);
		v->plane_y = old_plane_x * \
		sin(v->rot_speed) + v->plane_y * cos(v->rot_speed);
	}
	if (keycode == 53)
		clear_all(NULL, NULL, NULL, 0);
}

void	key_hook_3(int keycode, t_vars *v)
{
	double	olddir_x;
	double	old_plane_x;

	if (keycode == 124 || v->mouse_movement == 1)
	{
		olddir_x = v->dir_x;
		v->dir_x = v->dir_x \
		* cos(-v->rot_speed) - v->dir_y * sin(-v->rot_speed);
		v->dir_y = olddir_x \
		* sin(-v->rot_speed) + v->dir_y * cos(-v->rot_speed);
		old_plane_x = v->plane_x;
		v->plane_x = v->plane_x \
		* cos(-v->rot_speed) - v->plane_y * sin(-v->rot_speed);
		v->plane_y = old_plane_x \
		* sin(-v->rot_speed) + v->plane_y * cos(-v->rot_speed);
	}
	else
		key_hook_4(keycode, v);
}

void	key_hook_2(int keycode, t_vars *v)
{
	double	right_x;
	double	right_y;

	right_x = v->dir_y;
	right_y = -v->dir_x;
	if (keycode == 2)
	{
		if (v->map->content[(int)(v->pos_y)] \
		[(int)(v->pos_x + right_x * v->move_speed)] == '0')
			v->pos_x += right_x * v->move_speed;
		if (v->map->content[(int)(v->pos_y + right_y * v->move_speed)] \
		[(int)(v->pos_x)] == '0')
			v->pos_y += right_y * v->move_speed;
	}
	else if (keycode == 0)
	{
		if (v->map->content[(int)(v->pos_y)] \
		[(int)(v->pos_x - right_x * v->move_speed)] == '0')
			v->pos_x -= right_x * v->move_speed;
		if (v->map->content[(int)(v->pos_y - right_y * v->move_speed)] \
		[(int)(v->pos_x)] == '0')
			v->pos_y -= right_y * v->move_speed;
	}
	else
		key_hook_3(keycode, v);
}

int	key_hook(int keycode, t_vars *v)
{
	if (keycode == 13)
	{
		if (v->map->content[(int)(v->pos_y)] \
		[(int)(v->pos_x + v->dir_x * v->move_speed)] == '0')
			v->pos_x += v->dir_x * v->move_speed;
		if (v->map->content[(int)(v->pos_y + v->dir_y * v->move_speed)] \
		[(int)(v->pos_x)] == '0')
			v->pos_y += v->dir_y * v->move_speed;
	}
	else if (keycode == 1)
	{
		if (v->map->content[(int)(v->pos_y)] \
		[(int)(v->pos_x - v->dir_x * v->move_speed)] == '0')
			v->pos_x -= v->dir_x * v->move_speed;
		if (v->map->content[(int)(v->pos_y - v->dir_y * v->move_speed)] \
		[(int)(v->pos_x)] == '0')
			v->pos_y -= v->dir_y * v->move_speed;
	}
	else
		key_hook_2(keycode, v);
	renderer(v);
	return (0);
}
